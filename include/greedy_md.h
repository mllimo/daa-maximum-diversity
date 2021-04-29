#ifndef GREEDY_MD_H
#define GREEDY_MD_H

#include <strategy_md.h>
#include <vector_utility.h>

class GreedyMd : public StrategyMd {
 public:
  virtual ~GreedyMd();

  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m);
};

#endif