#include <local_search_md.h>

LocalSeachMd::~LocalSeachMd() {}

float LocalSeachMd::Z(const std::set<std::vector<float>>& solution) const {
  std::vector<std::vector<float>> vector_data(data_->begin(), data_->end());
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

void LocalSeachMd::UpdateSolution(std::set<std::vector<float>>& solution,
                      std::vector<std::vector<float>>& neighbour_solution) {
  std::set<std::vector<float>> aux(neighbour_solution.begin(), neighbour_solution.end());
  if (Z(aux) > Z(solution)) {
    solution = aux;
  }
}

void LocalSeachMd::UpdateSolution(std::set<std::vector<float>>& solution,
                      std::set<std::vector<float>>& neighbour_solution) {
  if (Z(neighbour_solution) > Z(solution)) {
    solution = neighbour_solution;
  }
}