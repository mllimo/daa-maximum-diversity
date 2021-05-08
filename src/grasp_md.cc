#include <grasp_md.h>

GraspMd::GraspMd(size_t k, StopConditionMd* stop, LocalSeachMd* local) {
  this->k = k;
  stop_condition = stop;
  local_search = local;
}

GraspMd::~GraspMd() { 
  delete stop_condition;
  if (local_search != NULL)
    delete local_search;
}

void GraspMd::operator()(std::set<std::vector<float>>& solution,
                         const std::set<std::vector<float>>& data, const size_t m) {
  std::set<std::vector<float>> actual_solution;
  const std::vector<std::vector<float>> vector_data(data.begin(), data.end());
  do {
    actual_solution.clear();
    Construct(actual_solution, data, m);
    if (local_search != NULL) (*local_search)(actual_solution, data);
  } while ((*stop_condition)(actual_solution, solution, vector_data)); /*condicion de parada + actualizacion de solucion*/
}

void GraspMd::Construct(std::set<std::vector<float>>& solution,
                        const std::set<std::vector<float>>& data, const size_t m) {
  std::vector<std::vector<float>> random_list;
  std::set<std::vector<float>> actual_candidates = data;
  std::vector<float> candidate;
  auto gravity_center = GravityCenter(actual_candidates);

  while (solution.size() < m) {
    random_list = MakeRcl(actual_candidates, gravity_center);
    if (random_list.size() == 0) break;
    candidate = SelectionRandom(random_list);
    actual_candidates.erase(candidate);
    solution.insert(candidate);
    gravity_center = GravityCenter(solution);
  }
}

std::vector<std::vector<float>> GraspMd::MakeRcl(std::set<std::vector<float>> actual_candidates,
                                                 const std::vector<float>& point) {
  std::vector<std::vector<float>> best_candidates;
  std::vector<float> candidate;
  for (size_t i = 0; i < k && actual_candidates.size() > 0; ++i) {
    candidate = Selection(actual_candidates, point);
    actual_candidates.erase(candidate);
    best_candidates.push_back(candidate);
  }
  return best_candidates;
}

std::vector<float> GraspMd::SelectionRandom(const std::vector<std::vector<float>>& random_list) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> distrib(0, random_list.size() - 1);
  return random_list[distrib(gen)];
}