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


int main() 
{
  cout << fixed << setprecision(5);
  for (double x = -10; x <= 0.81; x += 0.05) 
    cout << "x = " << x << " " << "y = " << getY(x) << " " << "\n";
  return (0);
}

double getY(const double x) 
{
  double ans = tan(x) - ((1 / 3) * pow(tan(x), 3)) + (0.2 * pow(tan(x), 5)) - (1 / 3);
  return (ans);
}
