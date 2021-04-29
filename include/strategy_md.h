#ifndef STRATEGY_MD_H
#define STRATEGY_MD_H

#include <iostream>
#include <limits>
#include <set>
#include <vector>

/**
 * @brief Clase interfaz para poder realizar el patrón estrategia dentro
 * del problam PSM
 */
class StrategyMd {
 public:
  virtual ~StrategyMd();
  virtual void operator()(std::set<std::vector<float>>& solution,
                     const std::set<std::vector<float>>& data, const size_t m) = 0;
};

#endif