#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;

double option(const double a, const double x);
double Func1(const double a, const double x);
double Func2(const double a, const double x);

int main()
{
    setlocale(0, "rus");
    double x;
    cout << "Введите число: " << endl;
    cin >> x;
    const double a = 20.3;

    cout << option(a, x) << endl;
    return 0;
}

double option(const double a, const double x)
{
    if (x > 1)
    {
        return Func1(a, x);
    }
    else
        if (x <= 1)
        {
            return Func2(a, x);
        }
}

double Func1(const double a, const double x)
{
    return log(x + 1);
}

double Func2(const double a, const double x)
{
    return sin(2) * sqrt(abs(a * x));
}