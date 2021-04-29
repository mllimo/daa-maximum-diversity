#include <greedy_local_md.h>

GreedyLocalMd::GreedyLocalMd(LocalSeachMd* local_search_) : local_search(local_search_) {}

GreedyLocalMd::~GreedyLocalMd() {}

void GreedyLocalMd::operator()(std::set<std::vector<float>>& solution,
                               const std::set<std::vector<float>>& data, const size_t m) {
  Greedy(solution, data, m);
  (*local_search)(solution, data);
}

void GreedyLocalMd::Greedy(std::set<std::vector<float>>& solution,
                           const std::set<std::vector<float>>& data, const size_t m) {
  auto elements = data;
  solution.clear();
  auto gravity_center = GravityCenter(elements);
  do {
    auto pair = solution.insert(Selecction(elements, gravity_center));
    elements.erase(*(pair.first));
    gravity_center = GravityCenter(solution);
  } while (solution.size() < m);
}