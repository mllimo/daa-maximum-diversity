#include <selection_depth.h>

SelectionDepth::~SelectionDepth() {}

Node* SelectionDepth::operator()(const std::multiset<std::pair<float, Node*>>& data) {
  Node* best_node = NULL;
  for (const auto& pair : data) {
    if (best_node == NULL)
      best_node = pair.second;
    else if (pair.second->depth > best_node->depth)
      best_node = pair.second;
  }
  return best_node;
}
