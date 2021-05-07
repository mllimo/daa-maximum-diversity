#ifndef GREEDY_MD_H
#define GREEDY_MD_H

#include <strategy_md.h>
#include <vector_utility.h>

class GreedyMd : public StrategyMd {
 public:
  virtual ~GreedyMd();

  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data, const size_t m);

 protected:
  /**
   * @brief Devuelve el mejor candidado. En este caso el vector más alejado al punto dado
   * @param vectors Conjunto de vectores
   * @param point Punto de referencia
   */
  virtual std::vector<float> Selection(const std::set<std::vector<float>>& vectors,
                                        const std::vector<float>& point);
};

#endif