#include <stop_condition_md.h>

StopConditionMd::~StopConditionMd() {}

float StopConditionMd::Z(const std::set<std::vector<float>>& solution,
                         const std::vector<std::vector<float>>& data) {
  float z = 0;
  for (size_t i = 0; i < data.size() - 1; ++i) {
    if (solution.find(data[i]) == solution.end()) continue;
    for (size_t j = i + 1; j < data.size(); ++j) {
      if (solution.find(data[j]) == solution.end()) continue;
      z += Distance(data[i], data[j]);
    }
  }
  return z;
}