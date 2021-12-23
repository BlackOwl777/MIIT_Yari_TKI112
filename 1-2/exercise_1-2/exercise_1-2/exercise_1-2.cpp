#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;
/*
* @brief вычисление площади конуса
* @param radius радиус 
* @param lenght длина
* @return площадь поверхности
*/
double getSquare(const double radius, const double lenght);

/*
* @brief вычисление высоты конуса
* @param radius радиус
* @param lenght длина
* @return высота конуса
*/
double getHeight(const double radius, const double lenght);

/*
* @brief вычисление объема конуса
* @param radius радиус
* @param lenght длина
* @return объем конуса
*/
double getVolume(const double radius, const double lenght);

int main()
{
    setlocale(0, "rus");
    double r;
    cout << "Введите Радиус: ";
    cin >> r;
    double l;
    cout << " Введите длину: ";
    cin >> l;
    cout << "Площадь конуса равна: " << getSquare(r, l);
    cout << "Объем конуса равен: " << getVolume(r, l);
}

double getSquare(const double radius, const double lenght)
{
    return (M_PI * radius * lenght + (radius * radius));
}

double getHeight(const double radius, const double lenght)
{
    return (2 * radius * (pow(radius, 2) - 1) / pow(radius, 2))
}

double getVolume(const double radius, const double lenght)
{
    return ((1.0 / 3) * getSquare(radius, lenght) * getHeight(radius, lenght));
}
