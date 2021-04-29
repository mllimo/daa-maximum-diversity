#include <greedy_md.h>

GreedyMd::~GreedyMd() {}

void GreedyMd::operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m) {
  auto elements = data;
  solution.clear();
  auto gravity_center = GravityCenter(elements);
  do {

  } while (solution.size() == m);
}