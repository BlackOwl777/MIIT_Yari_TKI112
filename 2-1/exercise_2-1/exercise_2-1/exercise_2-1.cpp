#include <iostream>
#include <cmath>
using namespace std;
enum days
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};
enum months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
};
int main()
{
    
    setlocale(0, "rus");

    cout << "Введите номер месяца: ";
    int month;
    cin >> month;

    const auto choice = static_cast<months>(month);
    switch (choice)
    {
    case months::January:
    {
        cout << "Январь";
        break;
    }
    case months::February:
    {
        cout << "Февраль";
        break;
    }
    case months::March:
    {
        cout << "Март";
        break;
    }
    case months::April:
    {
        cout << "Апрель";
        break;
    }
    case months::May:
    {
        cout << "Май";
        break;
    }
    case months::June:
    {
        cout << "Июнь";
        break;
    }
    case months::July:
    {
        cout << "Июль";
        break;
    }
    case months::August:
    {
        cout << "Август";
        break;
    }
    case months::September:
    {
        cout << "Сентябрь";
    }
    case months::October:
    {
        cout << "Октябрь";
        break;
    }
    case months::November:
    {
        cout << "Ноябрь";
        break;
    }
    case months::December:
    {
        cout << "Декабрь";
        break;
    }
    }

    cout << "Введите номер дня недели: ";
    int day;    
    cin >> day;

    const auto chosen = static_cast<days>(day);
    switch(chosen)
    {
    case days::Monday:
    {
        cout << "Понедельник";
        break;
    }
    case days::Tuesday:
    {
        cout << "Вторник";
        break;
    }
    case days::Wednesday:
    {
        cout << "Среда";
        break;
    }
    case days::Thursday:
    {
        cout << "Четверг";
        break;
    }
    case days::Friday:
    {
        cout << "Пятница";
        break;
    }
    case days::Saturday:
    {
        cout << "Суббота";
        break;
    }
    case days::Sunday:
    {
        cout << "Воскресенье";
        break;
    }
    }
}
