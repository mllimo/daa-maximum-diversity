#ifndef SELECTION_FUNCTION_H
#define SELECTION_FUNCTION_H

#include <set>
#include <vector>
#include <node_md.h>

class SelectionFunction {
 public:
  virtual ~SelectionFunction();
  /**
   * @brief Interfaz para la función que elegirá al mejor candidado del conjunto de datos pasado por parámetros.
   * @param data Conjunto de datos parcial del problema.
   * @return Node* Mejor candidato.
   */
  virtual Node* operator()(const std::multiset<std::pair<float, Node*>>& data) = 0;
};

#endif