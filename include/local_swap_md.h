#ifndef LOCAL_SWAP_MD_H
#define LOCAL_SWAP_MD_H

#include <local_search_md.h>

class LocalSwapMd : public LocalSeachMd {
 public:
  virtual ~LocalSwapMd();
  virtual void operator()(std::set<std::vector<float>>& solution, const std::set<std::vector<float>>& data) = 0;
};

#endif