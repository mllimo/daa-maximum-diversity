#include <branch_bound_md.h>

BranchBoundMd::BranchBoundMd(StrategyMd* algorithm, SelectionFunction* selection)
    : upper_bound_algorithm(algorithm), selection_function(selection) {}

BranchBoundMd::~BranchBoundMd() {
  delete upper_bound_algorithm;
  delete selection_function;
  DestroyTree();
}

void BranchBoundMd::DestroyTree() {
  for (auto it = initial_nodes.begin(); it != initial_nodes.end(); it++) {
    delete (*it).second;
  }
}

void BranchBoundMd::operator()(std::set<std::vector<float>>& solution,
                               const std::set<std::vector<float>>& data, const size_t m) {
  this->m = m;
  vector_data.insert(vector_data.begin(), data.begin(), data.end());
  (*upper_bound_algorithm)(solution, data, m);
  upper_bound = Z(solution);

  // Poda y ramificación
  InitializeTree();
  while (this->data.size() > 0) {
    Node* selected_node = (*selection_function)(this->data);
    ExpandNode(selected_node, upper_bound);
    if (solutions_found.size() > 0) {
      upper_bound = UpdateBound();
    }
    RemoveNodes(upper_bound);
  }

  // Asignamos valor a la solución
  if (node_solution != NULL && Z(node_solution->partial_solution) < Z(solution)) {
    solution.clear();
    for (size_t i = 0; i < node_solution->partial_solution.size(); ++i) {
      if (node_solution->partial_solution[i]) solution.insert(vector_data[i]);
    }
  }
}

void BranchBoundMd::InitializeTree() {
  std::vector<bool> partial_solution(vector_data.size(), false);
  for (size_t i = 0; i < vector_data.size(); ++i) {
    partial_solution[i] = true;
    float bound = GetUpperBound(partial_solution);
    Node* node = new Node(bound, 1, partial_solution);
    initial_nodes.insert(std::make_pair(bound, node));
    data.insert(std::make_pair(bound, node));
  }
}

void BranchBoundMd::ExpandNode(Node* selected_node, float limit) {
  const std::vector<bool>& partial_solution = selected_node->partial_solution;
  for (size_t i = 0; i < partial_solution.size(); ++i) {
    if (partial_solution[i] == false) {
      std::vector<bool> temp = partial_solution;
      temp[i] = true;
      float bound = GetUpperBound(temp);
      if (bound > limit) {
        // Añadir hijo a selected_node
        size_t solution_depth = selected_node->depth + 1;
        Node* new_node = new Node(solution_depth, bound, temp);
        selected_node->childs.push_back(new_node);
        data.insert(std::make_pair(bound, new_node));
        if (solution_depth == m) {
          solutions_found.insert(std::make_pair(bound, new_node));
        }
      }
    }
  }
  data.erase(data.find(std::pair<float, Node*>(selected_node->bound, selected_node)));
}

void BranchBoundMd::RemoveNodes(float bound) {
  std::multiset<std::pair<float, Node*>>::iterator it;
  for (it = data.begin(); it != data.end(); it++) {
    if ((*it).first <= bound) {
      data.erase(it);
    }
  }
}

float BranchBoundMd::UpdateBound() {
  float new_bound = (*solutions_found.rbegin()).first;
  node_solution = (*solutions_found.rbegin()).second;
  solutions_found.clear();
  return new_bound;
}

// Calculo límite superior
float BranchBoundMd::GetUpperBound(const std::vector<bool>& partial_solution) const {
  size_t selected = 0;
  for (size_t i = 0; i < partial_solution.size(); ++i) {
    if (partial_solution[i]) {
      selected++;
    }
  }

  std::multiset<float> temp;  // Mejorar eficiencia con un IFs
  for (size_t i = 0; i < partial_solution.size(); ++i) {
    if (!partial_solution[i]) {
      float contribution = GetContribution(partial_solution, i);
      temp.insert(contribution);
    }
  }

  int limit = m - selected;
  std::multiset<float>::reverse_iterator it = temp.rbegin();
  float result = Z(partial_solution);
  for (int i = 0; i < limit; i++) {
    result += *it;
  }
  return result;
}

float BranchBoundMd::GetContribution(const std::vector<bool>& current_solution, size_t id) const {
  float result = GetPotentialContribution(current_solution, id);
  size_t selected = 0;
  for (size_t i = 0; i < current_solution.size(); i++) {
    if (current_solution[i]) {
      selected++;
    }
  }
  result += GetContributionUnselected(current_solution, selected, id);
  return result;
}

float BranchBoundMd::GetPotentialContribution(const std::vector<bool>& current_solution,
                                              size_t id) const {
  float result = 0.0;
  for (size_t i = 0; i < current_solution.size(); i++) {
    if (current_solution[i]) {
      result += Distance(vector_data[i], vector_data[id]);
    }
  }
  return result;
}

float BranchBoundMd::GetContributionUnselected(const std::vector<bool>& current_solution,
                                               size_t selected, size_t id) const {
  float result = 0.0;
  std::multiset<float> temp;
  int limit = m - selected - 1;
  for (size_t i = 0; i < current_solution.size(); i++) {
    if (i != id && !current_solution[i]) {
      temp.insert(Distance(vector_data[id], vector_data[i]));
    }
  }
  std::multiset<float>::reverse_iterator it = temp.rbegin();
  for (int i = 0; i < limit; i++) {
    result += *it;
    it++;
  }
  return 0.5 * result;
}

float BranchBoundMd::Z(const std::set<std::vector<float>>& solution) const {
  float z = 0;
  for (size_t i = 0; i < vector_data.size() - 1; ++i) {
    if (solution.find(vector_data[i]) == solution.end()) continue;
    for (size_t j = i + 1; j < vector_data.size(); ++j) {
      if (solution.find(vector_data[j]) == solution.end()) continue;
      z += Distance(vector_data[i], vector_data[j]);
    }
  }
  return z;
}

float BranchBoundMd::Z(const std::vector<bool>& bool_solution) const {
  float z = 0;
  for (size_t i = 0; i < bool_solution.size() - 1; i++) {
    if (bool_solution[i]) {
      for (size_t j = i + 1; j < bool_solution.size(); j++) {
        if (bool_solution[j]) {
          z += Distance(vector_data[i], vector_data[j]);
        }
      }
    }
  }
  return z;
}

size_t BranchBoundMd::GetGeneratedNodes() const {
  return 0;
}