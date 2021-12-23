#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
* \brief вычисление значения функции
* \param x значение переменной x
* \return значение функции
*/
double getY(const double x);

/*
* \brief выполняет функцию 
* \param x значение переменной x
* \return 0, в случае успеха
*/
double NoGetY(const double x);

/*
* \brief точка входа в программу
* \return 0, в случае успеха
*/
int main() 
{
  cout << fixed << setprecision(5);
  double x = -10;
  const auto edge = 0.80;
  const auto step = 0.05;

  for (x; x <= edge; x += step)
  {
    if (NoGetY(x))
    {
      cout << "Нет решений" << endl;
    }
    cout << "x = " << x << " " << "y = " << getY(x) << " " << "\n";
  }
    
  return 0;
}

double getY(const double x) 
{
  return tan(x) - ((1.0 / 3.0) * pow(tan(x), 3)) + (0.2 * pow(tan(x), 5)) - (1.0 / 3.0);
}

double NoGetY(const double x)
{
  return (1/(tan(x) - ((1.0 / 3.0) * pow(tan(x), 3)) + (0.2 * pow(tan(x), 5)) - (1.0 / 3.0)));
}
