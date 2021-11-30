#include<iostream>
#include <iomanip>
#include<cmath>

using namespace std;

double f(double x) {
	double ans = tan(x) - ((1 / 3) * pow(tan(x), 3)) + (0.2 * pow(tan(x), 5)) - (1 / 3);
	return (ans);
}

int main() {
	cout << fixed;
	for (double x = 0; x <= 0.81; x += 0.05) {
		cout << setprecision(5) << "y = " << f(x) << " " << "x = " << x << endl;
	}
}