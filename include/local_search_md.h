#ifndef LOCAL_SEARCH_MD_H
#define LOCAL_SEARCH_MD_H

#include <vector_utility.h>

#include <set>
#include <vector>

class LocalSeachMd {
 public:
  LocalSeachMd();
  virtual ~LocalSeachMd();

  /**
   * @brief Genera una búsqueda local sobre la solución
   * @param solution Solución donde se aplicará el la búsqueda local y finalmente si es mejor
   * la solución de la búsqueda local que la actual la sustituye
   * @param data Datos del problema
   */
  virtual void operator()(std::set<std::vector<float>>& solution,
                          const std::set<std::vector<float>>& data) = 0;

 protected:
  const std::set<std::vector<float>>* data_;
  std::vector<std::vector<float>> vector_data;
  float Z(const std::set<std::vector<float>>& solution) const;
  void UpdateSolution(std::set<std::vector<float>>& solution,
                      std::vector<std::vector<float>>& neighbour_solution);
  void UpdateSolution(std::set<std::vector<float>>& solution,
                      std::set<std::vector<float>>& neighbour_solution);
};

#endif