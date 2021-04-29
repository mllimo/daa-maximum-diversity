#include <greedy_md.h>

GreedyMd::~GreedyMd() {}

void GreedyMd::operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m) {
  auto elements = data;
  solution.clear();
  auto gravity_center = GravityCenter(elements);
  do {
    auto pair = solution.insert(std::move(Selecction(elements, gravity_center)));
    elements.erase(pair.first);
    gravity_center = GravityCenter(solution);
  } while (solution.size() < m);
}

std::vector<float> GreedyMd::Selecction(const std::set<std::vector<float>>& vectors,
                                         const std::vector<float>& point) {
  std::vector<float> farthest_vector;
  float farthest_distance = std::numeric_limits<float>::min(), aux_distance;
  for (const auto& vector : vectors) {
    aux_distance = Distance(point, vector);
    if (aux_distance > farthest_distance) {
      farthest_distance = aux_distance;
      farthest_vector = vector;
    }
  }
  return farthest_vector;
}