#include <vector_utility.h>

std::vector<float> GravityCenter(const std::set<std::vector<float>>& vectors) {
  float multiplier = 1 / vectors.size();
  std::vector<float> gravity_center(vectors.begin()->size(), 0.f);
  for (size_t i = 0; i < vectors.size(); ++i) {
    for (const auto& vector : vectors) {
      gravity_center[i] += vector[i];
    }
  }
  return multiplier * gravity_center;
}

float Distance(const std::vector<float>& vector_a, const std::vector<float>& vector_b) {
  float distance = 0.f;
  for (size_t i = 0; i < vector_a.size(); i++) {
    distance += pow((vector_a[i] - vector_b[i]), 2);
  }
  return sqrt(distance);
}

std::vector<float> GetFarthestVectorFrom(const std::set<std::vector<float>>& vectors,
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

std::vector<float> operator*(float multiplier, const std::vector<float>& vector) {
  std::vector<float> solution(vector.size());
  for (size_t i = 0; i < solution.size(); ++i) {
    solution[i] = multiplier * vector[i];
  }
  return solution;
}