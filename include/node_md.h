#ifndef NODE_MD_H
#define NODE_MD_H

#include <iostream>
#include <set>
#include <vector>

/**
 * @brief Clase contenedora para almacenar información relevante para el algoritmo de ramificación y
 * poda
 */
class Node {
 public:
  /**
   * @brief Compuesto por todos los elementos del problema. Si el indice del elemento del problema
   * está a true significa que pertenece a la solución parcial del nodo, en caso contrario, no
   */
  std::vector<bool> partial_solution;
  
  /**
   * @brief Nodos hijos del nodo
   */
  std::vector<Node*> childs;

  /**
   * @brief Cota asignada al nodo
   */
  float bound;

  /**
   * @brief profundidad en donde se encuentra el nodo
   */
  size_t depth;

  /**
   * @brief Constructor para dar valor a los elementos de la clase
   * @param bound_ Cota del nodo
   * @param depth_ Profundidad del nodo
   * @param partial_solution_ Solución parcial que contiene el nodo
   */
  Node(float bound_, size_t depth_, const std::vector<bool>& partial_solution_);
  ~Node();
};

#endif