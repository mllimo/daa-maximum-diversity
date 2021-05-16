#ifndef NODE_MD_H
#define NODE_MD_H

#include <iostream>
#include <set>
#include <vector>

class Node {
 public:
  std::vector<bool> partial_solution;
  std::vector<Node*> childs;
  float bound;
  size_t depth;

  Node(float bound_, size_t depth_, const std::vector<bool>& partial_solution_);
  ~Node();
};

#endif