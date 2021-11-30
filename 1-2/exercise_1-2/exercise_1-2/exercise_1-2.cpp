#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	setlocale(0, "rus");
	double H;
	cout << "Введите высоту конуса: ";
	cin >> H;
	double L;
	cout << "Длину образующей конуса: ";
	cin >> L;
	double R = H / 2;
	double S = (M_PI * (R * R)) + (M_PI * R * L);
	cout << "Площадь полной поверхности конуса: ";
	cout << S << endl;
	double V = 0.3333333333 * H * M_PI * (R * R);
	cout << "Объём: ";
	cout << V << endl;
	return 0;
}


