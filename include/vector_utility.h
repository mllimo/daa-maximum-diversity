#ifndef VECTOR_UTILITY_H
#define VECTOR_UTILITY_H

#include <set>
#include <vector>
#include <cmath>

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

std::vector<float> operator*(float multiplier, const std::vector<float>& vector);

#endif