#include <iostream>
#include <cmath>
#include <random>

using namespace std;


/**
* \brief Заменить минимальный по модулю положительный элемент массива последним.
* \param arr массив.
* \param size размер массива.
*/
void getReplacingArray(int* arr, size_t size);
/**
* \brief поиск минимального элемента
* \param arr массив
* \param size размер массива
* \return значение минимального элемента массива
*/
int findMin(int* arr, size_t size);
/**
* \brief Удаление нечетных элементов, кратных 3.
* \param arr массив.
* \param size размер массива.
* \return количество элементов измененного массива.
*/
size_t getOddElements(int* arr, size_t size);
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
    int* sourceArray = new int[size];

    size_t key;
    do
    {
        cout << "Заполнить массив: " << "\nС клавиаутры - " << static_cast<int>(Choice::KEYBOARD) << "\nСлучайными числами - " << static_cast<int>(Choice::RANDOM) << "\nВведите опцию" << endl;
        cin >> key;
    } while (key != static_cast<int>(Choice::KEYBOARD) && key != static_cast<int>(Choice::RANDOM));

    if (key == static_cast<int>(Choice::KEYBOARD))
    {
        FillArrayKeyboard(sourceArray, size);
    }
    else if (key == static_cast<int>(Choice::RANDOM))
    {
        FillArrayRandom(sourceArray, size);
    }
    else
    {
        cout << "Неверный ввод!\n";
        return 0;
    }

    cout << "Исходный массив: " << "\n";
    printArray(sourceArray, size);

    cout << "\n" << "Метод1:" << "\n";
    getReplacingArray(sourceArray, size);
    printArray(sourceArray, size);

    cout << "\n" << "Метод2: " << "\n";
    int newSize = getOddElements(sourceArray, size);
    printArray(sourceArray, newSize);

    cout << endl << "Метод3: " << "\n";
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

void getReplacingArray(int* arr, size_t size)
{
    int min = findMin(arr, size);

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == min)
        {
            arr[i] = arr[size - 1];
            break;
        }
    }
}

int findMin(int* arr, size_t size)
{
    int min = arr[0];

    for (size_t i = 0; i < size - 1; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return (min);
}


void printArray(int* arr, size_t size)

{
    for (size_t i = 0; i < size; i++) cout << arr[i] << ' ';
}

size_t getOddElements(int* arr, size_t size)
{
    size_t newSize = size;
    for (size_t i = 0; i < size ; i++) 
    {
        if (arr[i] % 3 == 0 && ((arr[i] % 10) % 2 != 0))
        {
            newSize--;
            for (int j = i; j < newSize; ++j)
                arr[j] = arr[j + 1];
        }
    }

    return newSize;
}

int* getNewArray(int* arr, size_t size)
{
    int* newArrayA = new int[size];
    for (size_t i = 0; i < size; i++) {
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
