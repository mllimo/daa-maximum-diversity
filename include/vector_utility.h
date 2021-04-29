#ifndef VECTOR_UTILITY_H
#define VECTOR_UTILITY_H

#include <cmath>
#include <set>
#include <vector>
#include <limits>

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
 * @brief Devuelve el vector más alejado en base a un punto
 * @param vectors Conjunto de vectores
 * @param point Punto de referencia
 */
std::vector<float> GetFarthestVectorFrom(const std::set<std::vector<float>>& vectors,
                                         const std::vector<float>& point);

std::vector<float> operator*(float multiplier, const std::vector<float>& vector);
#endif