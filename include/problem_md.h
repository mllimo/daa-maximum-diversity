#ifndef PROBLEM_MD_H
#define PROBLEM_MD_H

#include <strategy_md.h>

#include <iostream>
#include <fstream>
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

  friend std::istream& operator>>(std::istream& is, ProblemMd& problem);

 private:
  std::set<std::vector<float>> solution_;
  std::set<std::vector<float>> data_;
  StrategyMd* strategy_;
  size_t m_;
};

#endif