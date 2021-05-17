#ifndef SELECTION_DISTANCE_H
#define SELECTION_DISTANCE_H

#include <selection_function.h>

class SelectionDistance : public SelectionFunction {
 public:
  ~SelectionDistance();
  Node* operator()(const std::multiset<std::pair<float, Node*>>& data);
};

#endif