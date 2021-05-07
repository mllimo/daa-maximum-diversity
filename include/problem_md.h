#ifndef PROBLEM_MD_H
#define PROBLEM_MD_H

#include <strategy_md.h>
#include <vector_utility.h>

#include <fstream>
#include <iostream>
#include <string>

class ProblemMd {
 public:
  /**
   * @brief Constructor por parámetros
   * @param file_path Ruta del archivo que contendrá la información del problema
   * @param strategy Estrategia que se utilizará para resolver el problema
   * @param m Número de elementos del subconjunto que formarán la solución
   */
  ProblemMd(const std::string& file_path, StrategyMd* strategy, size_t m);
  ~ProblemMd();

  /**
   * @brief Función que resulve el problema y lo almacena dentro de la clase
   * miembro
   */
  void Solve();

  /**
   * @brief Devuelve la diversidad máxima de la solución encontrada
   * @return float
   */
  float Z() const;

  /**
   * @brief Convierte la solución a un string
   * @return std::string
   */
  std::string ToString();

  friend std::istream& operator>>(std::istream& is, ProblemMd& problem);

 private:
  size_t m_;
  std::set<std::vector<float>> solution_;
  std::set<std::vector<float>> data_;
  std::vector<std::vector<float>> vector_data;
  StrategyMd* strategy_;
};

#endif