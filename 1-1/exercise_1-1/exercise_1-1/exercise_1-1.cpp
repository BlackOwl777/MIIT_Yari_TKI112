#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    const double x = 0.2;
    const double y = 0.004;
    const double z = 1.1;
    double a = pow((x * x + z), 2); //pow-функция возводящая в квадрат
    double b = pow(sin(a), 3);
    double c = b - sqrt(x / y);
    double d = ((x * x) / z) + cos(x * x * x + y * y * y);
    cout << c << endl;
    cout << d;
    return 0;

}


