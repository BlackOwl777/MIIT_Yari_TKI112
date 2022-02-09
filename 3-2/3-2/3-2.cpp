#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief функция вычисления значения члена ряда.
 * param k номер члена ряда.
 * \return значение члена ряда.
 */
double getSumm(int k);

/**
* \brief функция нахождения факториала нужного для вычисления члена ряда
* \param k номер члена ряда
* \return факториал
*/
double getFactorial(int k);

/**
 * \brief точка входа в программу.
 * return 0 в случае успеха.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество членов ряда" << endl;
    int n;
    cin >> n;   
    double sum = 0.0;
    for (size_t k = 0; k < n; k++)
        sum += getSumm(k);
    cout << "Сумма ряда: " << sum;
    return 0;
}

double getSumm(int k) 
{
    return (1 / getFactorial(2 * k));
}

double getFactorial(int k)
{
    int factorial = 1;
    for (size_t i = 1; i <= k; i++)
        factorial *= i;
    return (factorial);
}
