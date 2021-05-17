#ifndef VECTOR_UTILITY_H
#define VECTOR_UTILITY_H

#include <cmath>
#include <set>
#include <vector>
#include <limits>
#include <string>

/**
 * @brief Devuelve el punto que representa el centro de gravedad del conjunto de puntos
 * @param vectors Conjunto de vectores
 * @return std::vector<float>
 */
std::vector<float> GravityCenter(const std::set<std::vector<float>>& vectors);

/**
 * @brief Devuelve la distancia entre dos vectores
 * @param vector_a Vector origen
 * @param vector_b Vector destino
 * @return float
 */
float Distance(const std::vector<float>& vector_a, const std::vector<float>& vector_b);

/**
 * @brief Sobrecarga de operador para poder multiplicar un escalar con un vector
 * @param multiplier Escalar
 * @param vector Vector
 * @return std::vector<float> Vector resultante 
 */
std::vector<float> operator*(float multiplier, const std::vector<float>& vector);

/**
 * @brief Convierte un vector a string
 * @param vector Vector a convertir a string
 * @return std::string Vector en formato de string
 */
std::string VectorToString(const std::vector<float>& vector);
#endif