#include <selection_distance.h>

SelectionDistance::~SelectionDistance() {}

Node* SelectionDistance::operator()(const std::multiset<std::pair<float, Node*>>& data) {
  Node* best_node = NULL;
  for (auto& pair : data) {
    if (best_node == NULL)
      best_node = pair.second;
    else if (pair.second->bound > best_node->bound)
      best_node = pair.second;
  }
  return best_node;
}