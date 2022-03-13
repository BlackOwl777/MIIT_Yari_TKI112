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
void getReplacingArray(int* arr, int size);
/**
* \brief Удаление нечетных элементов, кратных 3.
* \param arr массив.
* \param size размер массива.
* \return изменённый массив.
*/
int getOddElements(int* arr, int size);
/**
* \brief Создание нового массива по формуле
* \param arr массив.
* \param size размер массива.
* \return изменённый массив.
*/
int* getNewArray(int* arr, int* newArrayA, int size);
/**
* \brief Точка входа в программу.
* \return 0, в случае успеха.
*/

void FillArrayKeyboard(int* SourceArray, const size_t n);

void FillArrayRandom(int* SourceArray, const size_t n);

void printArray(int* arr, int size);

enum class Choice
{
  RANDOM,
  KEYBOARD
};

int main()
{
  setlocale(LC_ALL, "Russian");
  size_t n, key;
  int size;

  cout << "Введите размерность массива: ";
  cin >> size;


  while (size < 1)
  {
    cout << "Размер не может быть отрицательным, введите размер ещё раз:" << endl;
    cin >> size;
  }

  n = size;
  int* SourceArray = new int[n];

  do
  {
    cout << "Заполнить массив: " << "\nС клавиаутры - " << static_cast<int>(Choice::KEYBOARD) << "\nСлучайными числами - " << static_cast<int>(Choice::RANDOM) << "\nВведите опцию" << endl;
    cin >> key;
  } while (key != static_cast<int>(Choice::KEYBOARD) && key != static_cast<int>(Choice::RANDOM));
  
  if (key == static_cast<int>(Choice::KEYBOARD))
  {
    FillArrayKeyboard(SourceArray, n);
  }
  else
  {
    FillArrayRandom(SourceArray, n);
  }


  cout << "Исходный массив: " << endl;
  printArray(SourceArray, n);
  
  cout << endl << "Метод2: " << endl;
  getOddElements(SourceArray, n);
  printArray(SourceArray, n);

  cout << endl << "Метод3: " << endl;
  int *newArrayA = new int[n];
  newArrayA = getNewArray(SourceArray, newArrayA, n);
  printArray(newArrayA, n);

  if (SourceArray != nullptr)
  {
    delete[] SourceArray;
    SourceArray = nullptr;
  }
  if (newArrayA != nullptr)
  {
	  delete[] newArrayA;
	  newArrayA = nullptr;
  }


  return 0;
}


void printArray(int* arr, int size)

{
  for (int i = 0; i < size; i++) cout << arr[i] << ' ';
}

int getOddElements(int* arr, int size)
{
  int newSize = size;
  for (int i = size; i >= 0; i--) {
    if (arr[i] % 3 == 0 and arr[i] % 2 == 1) {
      newSize--;
      for (int j = i; j < newSize; ++j)
      {
        arr[j] = arr[j + 1];
      }
    }
  }

  return newSize;
}

int* getNewArray(int* arr, int *newArrayA, int size)
{

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 != 0)
      newArrayA[i] = arr[i] - i;
    else
      newArrayA[i] = arr[i] + i;
  }
  return (newArrayA);
}

void FillArrayKeyboard(int* SourceArray, const size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    cout << "array[" << i << "]: " << SourceArray[i];
    cin >> SourceArray[i];
  }
  cout << endl;
}

void FillArrayRandom(int* SourceArray, const size_t n)
{
  cout << "Массив будет заполнен случайным образом" << endl;
  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<mt19937::result_type> dist(0, 60);

  for (int i = 0; i < n; ++i)
  {
    SourceArray[i] = dist(rng) - 20;
  }
}
