#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
/**
 * @brief Функция для вычисление значения A
 * @param x параметр x
 * @param y параметр y
 * @param z параметр z
 * @return значение A
 */
double getA(const double x, const double y, const double z);

/**
 * @brief Функция для вычисление значения B
 * @param x параметр x
 * @param y параметр y
 * @param z параметр z
 * @return значение B
 */
double getB(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха
 */
int main()
{
    const double x = 0.2;
    const double y = 0.004;
    const double z = 1.1;
    double a = getA(x,y,z);
    double b = getB(x,y,z);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}

double getA(const double x, const double y, const double z)
{
    return sin(pow(x*x + z), 2) * sin(pow(x*x + z), 2) * sin(pow(x*x + z), 2) - sqrt(x/y)
}

double getB(const double x, const double y, const double z)
{
    return pow(x, 2) / z + cos(pow(x+y, 3))
}