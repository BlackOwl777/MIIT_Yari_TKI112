#define _USE_MATH_DEFINES 

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/
* \brief Функция расчета для случая, когда x > 1.
* \param x Входная величина.
* \param a Входная величина.
* \return Значение функции.
*/
double Func1(const double x);
/
* \brief Функция расчета для случая, когда x <= 1.
* \param x Входная величина.
* \param a Входная величина.
* \return Значение функции.
*/
double Func2(const double x, const double a);
/
* \brief Проверка варианта.
* \param x Входная величина.
* \param a Входная величина.
* \return Значение функции.
*/
double option(const double a, const double x, const double comparise, double result);

/
* \brief Точка входа в программу.
* \return Код ошибки (0 - успех).
*/
int main()
{
    setlocale(LC_ALL, "ru");
    const auto a = 20.3;
    const auto comparise = 1;
    double x;
    cout << "Введите переменную x = ";
    cin >> x;
    double result;
    cout << option(a, x) << endl;

    return 0;
}

double Func1(const double x)
{
    return log(x + 1);
}

double Func2(const double x, const double a)
{
    return sin(2) * sqrt(abs(a * x));
}

double option(const double a, const double x,const double comparise,double result)
{
    if (x > comparise)
        result = Func1(x);

    else

        result = Func2(x, a);

    cout << "y = " << setprecision(15) << result << endl;
}
