#include <iostream>
#include <cmath>

using namespace std;

/**/
/* brief Нахождение суммы n членов последовательности.
/* param n - количество складываемых членов.
/* return sum - искомая сумма
/**/
double getSum(const int n);

double getFactorial(const int n);

/**/
/* brief Точка входа в программу.
/* return 0 в случае успеха.
/**/
int main()
{
    int k = 0;
    int n = 1;
    cout << "Сколько членов последовательности сложить?\n";
    cin >> n;
    if (n < 2) {
        cout << "Неверное значение";
        return 1;
    }

    cout << "Сумма = " << getSum(n);
    return 0;
}

double getSum(const int n)
{
    double nk = 0;
    double sum = 0;
    for (size_t k = 0; k < n; k++)
    {
        nk = 1 / getFactorial(2 * k);
        sum += nk;
    }
    return sum;
}

double getFactorial(const int n)
{
    double factorial = 1;
    if (n == 0)
        return (1);
    for (size_t i = 1; i < n; i++)
        factorial *= i;
    return (factorial);
}