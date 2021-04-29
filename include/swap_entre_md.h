#ifndef SWAP_ENTRE_MD_H
#define SWAP_ENTRE_MD_H

#include <local_swap_md.h>

class SwapEntreMd : public LocalSwapMd {
 public:
  ~SwapEntreMd();
  void operator()(std::set<std::vector<float>>& solution, const std::set<std::vector<float>>& data);
};

#endif