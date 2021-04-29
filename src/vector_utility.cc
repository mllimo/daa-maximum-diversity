#include <vector_utility.h>

std::vector<float> GravityCenter(const std::set<std::vector<float>>& vectors) {
  float multiplier = 1 / vectors.size();
  std::vector<float> gravity_center(vectors.begin()->size(), 0.f);
  for (size_t i = 0; i < vectors.begin()->size(); ++i) {
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

std::string VectorToString(const std::vector<float>& vector) {
  std::string out = "( ";
  for (const auto& element : vector) {
    out += std::to_string(element) + ", ";
  }
  out.pop_back();
  out.pop_back();
  out += " )";
  return out;
}

std::vector<float> operator*(float multiplier, const std::vector<float>& vector) {
  std::vector<float> solution(vector.size());
  for (size_t i = 0; i < solution.size(); ++i) {
    solution[i] = multiplier * vector[i];
  }
  return solution;
}