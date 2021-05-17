#ifndef SELECTION_FUNCTION_H
#define SELECTION_FUNCTION_H

#include <set>
#include <vector>
#include <node_md.h>

class SelectionFunction {
 public:
  virtual ~SelectionFunction();
  virtual Node* operator()(const std::multiset<std::pair<float, Node*>>& data) = 0;
};

#endif