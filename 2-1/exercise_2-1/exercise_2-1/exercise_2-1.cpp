#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int day;
    setlocale(0, "rus");
    cout << "Введите номер дня недели: ";
    cin >> day;
    switch (day)
    {
    case 1: cout << "Понедельник/январь"; break;
    case 2: cout << "Вторник/февраль"; break;
    case 3: cout << "Среда/март"; break;
    case 4: cout << "Четверг/апрель"; break;
    case 5: cout << "Пятница/май"; break;
    case 6: cout << "Суббота/июнь"; break;
    case 7: cout << "Воскресенье/июль"; break;
    case 8: cout << "Август"; break;
    case 9: cout << "Сентябрь"; break;
    case 10: cout << "Октябрь"; break;
    case 11: cout << "Ноябрь"; break;
    case 12: cout << "Декабрь"; break;
    default: cout << "Неверно введен день "; break;
    }
    cin.get(); cin.get();
    return 0;
}