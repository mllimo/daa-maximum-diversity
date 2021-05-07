#include <stop_no_improvement_md.h>

StopNoImprovementMd::StopNoImprovementMd(size_t max_no_improvement)
    : StopConditionMd(), max_no_improvement_(max_no_improvement), no_improvement_counter_(0) {}

StopConditionMd::~StopConditionMd() {}

bool StopNoImprovementMd::operator()(std::set<std::vector<float>>& solution,
                                     std::set<std::vector<float>>& best_solution,
                                     const std::vector<std::vector<float>>& vector_data) {
  if (Z(solution, vector_data) > Z(best_solution, vector_data)) {
    best_solution = solution;
    no_improvement_counter_ = 0;
  } else {
    no_improvement_counter_ += 1;
  }
  return no_improvement_counter_ < max_no_improvement_;
}