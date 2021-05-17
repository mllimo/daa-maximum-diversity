#ifndef BRANCH_BOUND_MD_H
#define BRANCH_BOUND_MD_H

#include <node_md.h>
#include <selection_function.h>
#include <strategy_md.h>
#include <vector_utility.h>

#include <algorithm>
#include <set>
#include <vector>

class BranchBoundMd : public StrategyMd {
 public:
  BranchBoundMd(StrategyMd* algorithm, SelectionFunction* selection);
  virtual ~BranchBoundMd();
  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m);

  size_t GetGeneratedNodes() const;

 protected:
  size_t m;
  float upper_bound;
  Node* node_solution;
  size_t generated_nodes_counter;
  StrategyMd* upper_bound_algorithm;
  SelectionFunction* selection_function;
  std::vector<std::vector<float>> vector_data;
  std::multiset<std::pair<float, Node*>> data;
  std::multiset<std::pair<float, Node*>> initial_nodes;
  std::multiset<std::pair<float, Node*>> solutions_found;

  float Z(const std::vector<bool>& bool_solution) const;
  float Z(const std::set<std::vector<float>>& solution) const;

  float UpdateBound();
  void InitializeTree();
  void RemoveNodes(float bound);
  void ExpandNode(Node* selectedNode, float limit);
  float GetUpperBound(const std::vector<bool>& partial_solution) const;
  float GetContribution(const std::vector<bool>& current_solution,
                        size_t id) const;  // Calculo de Z(v)
  float GetPotentialContribution(const std::vector<bool>& current_solution,
                                 size_t id) const;  // Cálculo de Z-sel(v)
  float GetContributionUnselected(const std::vector<bool>& current_solution, size_t selected,
                                  size_t id) const;  // Cálculo de Z-unsel(v)

 private:
  void DestroyTree();
};

#endif