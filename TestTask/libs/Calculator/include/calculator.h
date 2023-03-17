#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <cmath>


double conversionFromDegreesToRadians(double degrees); // Функция для перевода из градусов в радианы
double conversionFromRadiansToDegrees(double radians); // Функция для перевода из радиан в градусы

std::vector<double> getUnitVector(double azimut, double elevationAngle); // Функция для получения единичного вектора
std::vector<double> rotationAroundAxes(double xAngle, double yAngle, double zAngle, std::vector<double>& coord); // Функция для поворота осей
std::vector<double> multiplicationVectorByMatrix(std::vector<double> vec, std::vector<std::vector<double>> matrix); // Функция для умножения вектора на матрицу


#endif // CALCULATOR_H
