#include <swap_entre_md.h>

SwapEntreMd::~SwapEntreMd() {}

void SwapEntreMd::operator()(std::set<std::vector<float>>& solution,
                             const std::set<std::vector<float>>& data) {
  data_ = &data;
  // Es más eficiente que estar trabajando con sets
  std::vector<std::vector<float>> copy_data(data.begin(), data.end());
  std::vector<std::vector<float>> neighbour_solution(solution.begin(), solution.end());
  for (size_t i = 0; i < neighbour_solution.size(); ++i) {
    for (size_t j = 0; j < data.size(); ++j) {
      std::swap(neighbour_solution[i], copy_data[j]);
      UpdateSolution(solution, neighbour_solution);
      std::swap(neighbour_solution[i], copy_data[j]);
    }
  }
}