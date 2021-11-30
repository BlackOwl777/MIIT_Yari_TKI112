#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

int main()
{
	setlocale(0, "rus"); //перевод на русские буквы
	cout<< "Введите силу тяги - F: ";
	double f = 0;
	cin >> f;
	cout << "Ведите значиние работы - A: ";
	double a = 0;
	cin >> a;

	double way = (a * 1000000) / (f * 1000);

	cout << "Путь пройденный автомобилем равен: " << way << endl;
	return 0;
}