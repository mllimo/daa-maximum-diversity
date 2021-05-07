#ifndef STOP_CONDITION_MD_H
#define STOP_CONDITION_MD_H

#include <iostream>
#include <set>
#include <vector>
#include <vector_utility.h>

class StopConditionMd {
 public:
  virtual ~StopConditionMd();
  /**
   * @brief Dada una implementación intenta marcar una condición de parada
   * para el algoritmo de GRASP. Si la solución actual es mejor que la mejor actual se cambia su
   * valor
   * @return true Se para el algoritmo
   * @return false No se para el algoritmo
   */
  virtual bool operator()(std::set<std::vector<float>>& solution,
                          std::set<std::vector<float>>& best_solution,
                          const std::vector<std::vector<float>>& vector_data) = 0;

 protected:
  float Z(const std::set<std::vector<float>>& solution, const std::vector<std::vector<float>>& data);
};

#endif