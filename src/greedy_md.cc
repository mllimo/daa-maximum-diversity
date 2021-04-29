#include <greedy_md.h>

GreedyMd::~GreedyMd() {}

void GreedyMd::operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m) {
  auto elements = data;
  solution.clear();
  auto gravity_center = GravityCenter(elements);
  do {
    auto pair = solution.insert(std::move(GetFarthestVectorFrom(elements, gravity_center)));
    elements.erase(pair.first);
    gravity_center = GravityCenter(solution);
  } while (solution.size() == m);
}