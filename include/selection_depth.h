#ifndef SELECTION_DEPTH_H
#define SELECTION_DEPTH_H

#include <selection_function.h>

class SelectionDepth : public SelectionFunction {
 public:
  ~SelectionDepth();
  Node* operator()(const std::multiset<std::pair<float, Node*>>& data);
};

#endif