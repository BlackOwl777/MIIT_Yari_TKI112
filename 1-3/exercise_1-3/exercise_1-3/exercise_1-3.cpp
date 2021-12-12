#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

/*
* @brief вычисление пути пройдёным машиной
* @param a совершенная работа
* @param f сила тяги
* @return путь пройденный автомобилем
*/
double getWay(const double a; const double f);



int main()
{
	setlocale(0, "rus"); //перевод на русские буквы
	cout<< "Введите силу тяги - F: ";
	double f = 0;
	cin >> f;
	cout << "Введите значиние работы - A: ";
	double a = 0;
	cin >> a;

	cout << "Путь пройденный автомобилем равен: " << getWay(a, f) << endl;
	return 0;
}

double getWay(const double a; const double f)
{
	return ((a * 1000000) / (f * 1000));
}
