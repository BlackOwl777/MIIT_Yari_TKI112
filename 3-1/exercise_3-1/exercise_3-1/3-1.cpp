#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/**
* \brief Возможность расчета функции в точке
* \param x Входной параметр - точка x
* \return true, если функция определена в заданной точке x
*/
bool IsCalculated(const double x);

/**
* \brief Расчет функции в точке x
* \param x Входной параметр - точка x
* \return Значение функции в точке x
*/
double Calculation(const double x);

/**
* \brief Точка входа в программу
* \return Код ошибки (0 - успех)
*/
void main()
{
	const auto leftBound = 0;
	const auto rightBound = 0.8;
	const auto step = 0.05;

	auto x = leftBound;
	cout << "  x" << setw(15) << "y\n";
	while ((x < rightBound) || (abs(x - rightBound) < step))
	{
		if (IsCalculated(x))
		{
			const auto y = Calculation(x);
			cout << setw(10) << setprecision(2) << x << setw(15)
				<< setprecision(5) << y << '\n';
		}
		else
		{
			cout << setw(10) << setprecision(2) << x << setw(15)
				<< "not defined \n";
		}
		x += step;
	}
}

double Calculation(const double x)
{
	return (1 / (tan(x) - ((1.0 / 3.0) * pow(tan(x), 3)) + (0.2 * pow(tan(x), 5)) - (1.0 / 3.0)));
}

bool IsCalculated(const double x)
{
	return (abs(x) > numeric_limits<long double>::epsilon());
}
