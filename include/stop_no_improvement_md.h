#ifndef STOP_NO_PERFORMANCE_MD_H
#define STOP_NO_PERFORMANCE_MD_H

#include <stop_condition_md.h>

class StopNoImprovementMd : public StopConditionMd {
 public:
  StopNoImprovementMd(size_t max_no_improvement_);
  ~StopNoImprovementMd();

  virtual bool operator()(std::set<std::vector<float>>& solution,
                          std::set<std::vector<float>>& best_solution,
                          const std::vector<std::vector<float>>& vector_data);
  private:
   size_t max_no_improvement_;
   size_t no_improvement_counter_;
};

#endif