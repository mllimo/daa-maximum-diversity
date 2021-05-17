#ifndef BRANCH_BOUND_MD_H
#define BRANCH_BOUND_MD_H

#include <node_md.h>
#include <selection_function.h>
#include <strategy_md.h>
#include <vector_utility.h>

#include <algorithm>
#include <list>
#include <set>
#include <vector>

class BranchBoundMd : public StrategyMd {
 public:
  BranchBoundMd(StrategyMd* algorithm, SelectionFunction* selection);
  virtual ~BranchBoundMd();

  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m);

  /**
   * @brief Devuelve el número de nodos generados dentro del problema. NOTA: solo cuenta los nodos
   * ampliados a partir de la primera capa de profundidad.
   * @return size_t Número de nodos generados
   */
  size_t GetGeneratedNodes() const;

 protected:
  size_t m;                                                 // Tamaño del problema
  float upper_bound;                                        // Cota superior del problema
  Node* node_solution;                                      // Nodo que contiene la mejor solución
  size_t generated_nodes_counter;                           // Variable para contabilizar los nodos generados
  StrategyMd* upper_bound_algorithm;                        // Algoritmo inicial para conseguir la cota superior
  SelectionFunction* selection_function;                    // Función para ramificar el árbol
  std::vector<std::vector<float>> vector_data;              // Los datos convertidos a un vector para mejorar eficiencia
  std::multiset<std::pair<float, Node*>> data;              // Conjunto de candidatos del problema
  std::multiset<std::pair<float, Node*>> initial_nodes;     // Nodos que componen a la primera capa del árbol
  std::multiset<std::pair<float, Node*>> solutions_found;   // Conjunto de soluciones encontradas

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