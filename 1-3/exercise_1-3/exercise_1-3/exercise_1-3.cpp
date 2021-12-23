#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

/*
* @brief вычисление пути пройдёным машиной
* @param work совершенная работа
* @param force сила тяги
* @return путь пройденный автомобилем
*/
double getWay(const double work, const double force);



int main()
{
	setlocale(0, "rus"); //перевод на русские буквы
	cout<< "Введите силу тяги - F: ";
	double force = 0;
	cin >> force;
	cout << "Введите значиние работы - A: ";
	double work = 0;
	cin >> work;

	cout << "Путь пройденный автомобилем равен: " << getWay(work, force) << endl;
	return 0;
}

double getWay(const double work, const double force)
{
	return ((work * 1000000) / (force * 1000));
}
