#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief рекурсивная функция для расчета значения.
 * param k число.
 * \return значение.
 */
double getSumm(int k);
/**
 * \brief функция нахождения факториала нужного для вычисления члена ряда.
 *  \param k номер члена ряда.
 *  \return факториал.
 */
double getFactorial(int k);

double getSumm(int k)  
{
    if (k == 0) {
        return 1;       
    } else {
        return ((1 / getFactorial(2 * k)) + getSumm(k - 1)); 
    }        
}
/**
 * \brief функция нахождения меньшей суммы.
 * \param an текущий член последовательности.
 * \return сумма всех членов последовательности.
 */
double getSummLessE(int k, double e)
{
    double an;
    an = (1 / getFactorial(2 * k)); 
    if ((an < e) or (k >= 1000)) {
        return 0;       
    } else {           
        return (an + getSummLessE(k + 1, e)); 
    }        
}

double getFactorial(int k)
{
    int factorial = 1;
    for (size_t i = 1; i <= k; i++)
        factorial *= i;
    return (factorial);
}
/**
 * \brief точка входа в программу 
 * return 0 в случае успеха
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    cout.setf(std::ios::fixed);
    cout.precision(10);

    cout << "Введите количество членов ряда: ";
    int n;
    cin >> n;    
    if (n < 0){
        cout << "n должно быть целым и не отрицательным, попробуйте ещё раз" << endl;
        return 0;
    }
    cout << "Сумма ряда: " << getSumm(n); 
    
    cout << '\n' << "Введите положительное рациональное число e: ";
    double e;
    cin >> e; 
    if (e < 0){
        cout << "e должно быть не отрицательным, попробуйте ещё раз" << endl;
        return 0;
    }    
    cout << "Сумма всех членов последователности меньших e: " << getSummLessE(0, e); 

    return 0;
}
