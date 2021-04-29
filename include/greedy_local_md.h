#ifndef GREEDY_LOCAL_MD_H
#define GREEDY_LOCAL_MD_H

#include <greedy_md.h>
#include <local_search_md.h>
class GreedyLocalMd : public GreedyMd {
 public:
  GreedyLocalMd(LocalSeachMd* local_search_);
  ~GreedyLocalMd();
  void operator()(std::set<std::vector<float>>& solution, const std::set<std::vector<float>>& data,
                  const size_t m);

 protected:
  LocalSeachMd* local_search;

  void Greedy(std::set<std::vector<float>>& solution, const std::set<std::vector<float>>& data,
              const size_t m);
};

#endif