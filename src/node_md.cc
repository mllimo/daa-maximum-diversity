#include <node_md.h>

Node::Node(float bound_, size_t depth_, const std::vector<bool>& partial_solution_) {
  bound = bound_;
  depth = depth_;
  partial_solution = partial_solution_;
}

Node::~Node() {
  for (auto node : childs) {
    if (node != NULL)
      delete node;
  }
}