#include <iostream>
#include <cmath>
#include <random>

using namespace std;


/**
* \brief Заменить минимальный по модулю положительный элемент массива последним.
* \param arr массив.
* \param size размер массива.
* \return измененный массив на максимальный среди отрицательных.
*/
void getReplacingArray(int* arr, size_t size);
/**
* \brief Удаление нечетных элементов, кратных 3.
* \param arr массив.
* \param size размер массива.
* \return количество элементов измененного массива.
*/
int getOddElements(int* arr, size_t size);
/**
* \brief Создание нового массива по формуле
* \param arr массив.
* \param size размер массива.
* \return изменённый массив.
*/
int* getNewArray(int* arr, size_t size);

/**
* \brief Заполнение массива с клавиатуры
* \param sourceArray массив
* \param n количество элементов массива
*/
void FillArrayKeyboard(int* sourceArray, const size_t n);

/**
* \brief Заполнение массива случайными числами
* \param sourceArray массив
* \param n количество элементов массива
*/
void FillArrayRandom(int* sourceArray, const size_t n);

/**
* \brief Вывод массива на экран
* \param arr массив
* \param size размер массива
*/
void printArray(int* arr, size_t size);

enum class Choice
{
    RANDOM,
    KEYBOARD
};

/**
* \brief Точка входа в программу.
* \return 0, в случае успеха.
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int size;

    cout << "Введите размерность массива: ";
    cin >> size;


    while (size < 1)
    {
        cout << "Размер не может быть отрицательным, введите размер ещё раз:" << endl;
        cin >> size;
    }
    size_t n;
    n = size;
    int* sourceArray = new int[size];
    
    size_t key;
    do
    {
        cout << "Заполнить массив: " << "\nС клавиаутры - " << static_cast<int>(Choice::KEYBOARD) << "\nСлучайными числами - " << static_cast<int>(Choice::RANDOM) << "\nВведите опцию" << endl;
        cin >> key;
    } while (key != static_cast<int>(Choice::KEYBOARD) && key != static_cast<int>(Choice::RANDOM));

    if (key == static_cast<int>(Choice::KEYBOARD))
    {
        FillArrayKeyboard(sourceArray, n);
    }
    else if (key == static_cast<int>(Choice::RANDOM))
    {
        FillArrayRandom(sourceArray, n);
    }

    cout << "Исходный массив: " << endl;
    printArray(sourceArray, n);

    cout << endl << "Метод2: " << endl;
    int newSize = getOddElements(sourceArray, n);
    printArray(sourceArray, newSize);

    cout << endl << "Метод3: " << endl;
    int* newArrayA = getNewArray(sourceArray, newSize);
    printArray(newArrayA, newSize);

    if (sourceArray != nullptr)
    {
        delete[] sourceArray;
        sourceArray = nullptr;
    }
    if (newArrayA != nullptr)
    {
        delete[] newArrayA;
        newArrayA = nullptr;
    }


    return 0;
}


void printArray(int* arr, size_t size)

{
    for (int i = 0; i < size; i++) cout << arr[i] << ' ';
}

int getOddElements(int* arr, size_t size)
{
    int newSize = size;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            newSize--;
            for (int j = i; j < newSize; ++j)
            {
                arr[j] = arr[j + 1];
            }
        }
    }

    return newSize;
}

int* getNewArray(int* arr, size_t size)
{
    int* newArrayA = new int[size];
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0)
            newArrayA[i] = arr[i] - i;
        else
            newArrayA[i] = arr[i] + i;
    }
    return (newArrayA);
}

void FillArrayKeyboard(int* sourceArray, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "array[" << i << "]: " << sourceArray[i];
        cin >> sourceArray[i];
    }
    cout << endl;
}

void FillArrayRandom(int* sourceArray, const size_t n)
{
    cout << "Массив будет заполнен случайным образом" << endl;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(0, 60);

    for (int i = 0; i < n; ++i)
    {
        sourceArray[i] = dist(rng) - 20;
    }
}
