#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

/**
*\brief Нахождение минимального по значению элемента
*\param array Массив
*\param size Размер массива
**/
size_t GetMin(const int* array, const size_t size);

/**
*\brief Нахождение среднего арифметического среди элементов массива
*\param array Массив
*\param size Размер массива
**/
int GetAverage(const int* array, const size_t size);

/**
*\brief Замена минимального элемента массива на среднее арифметическое
*\param array Массив
*\param size Размер массива
**/
void MinToAverage(int* array, const size_t size);

/**
*\brief Вывод индексов элементов, значение которых больше предыдущих
*\param array Массив
*\param size Размер массива
**/
void ShowIndex(int* array, const size_t size);
/**
*\brief Проверка на существование двух пар элементов с одинаковыми знаками
*\param array Массив
*\param size Размер массива
**/
bool CheckElement(int* array, const size_t size);

/**
* \brief Выбор заполнеия массива
**/
enum class Input
{
	randomize = 1,
	user = 2
};

/**
* \brief Заполнение массива случайными числами
* \array Массив
* \size Размер массива
* \param min Минимально возможное число
* \param max Максимально возможное число
**/
void randomizeArray(int* array, const size_t size, const int min, const int max);

/**
* \brief Ввод массива с клавиатуры
* \param array Массив
* \param size Размер массива
**/
void userInput(int* array, const size_t size);

/**
* \brief Конвертация массива строку вида {element_1, element_2, ... ,element_n}
* \param array Массив
* \param size Размер массива
* \param message Сообщение, которое будет выведено перед массивом
**/
string arrayToString(int* array, const size_t size, const string& message);

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	const int min = -20, max = 40;

	cout << "Введите размер массива\n";
	size_t size,choice;
	cin >> size;
	int* array = new int[size];

	cout << "Выберите способ заполнения массива:";
	cout << "Случайные элементы - " << static_cast<int>(Input::randomize);
	cout << "Ручной ввод - " << static_cast<int>(Input::user);
	cin >> choice;

	const auto input = static_cast<Input>(choice);

	switch (input)
	{
	case Input::randomize:
	{
		randomizeArray(array, size, min, max);
		cout << arrayToString(array, size, "массив = ") << "\n";
		break;
	}
	case Input::user:
	{
		userInput(array, size);
		cout << arrayToString(array, size, "массив = ") << "\n";
		break;
	}
	default:
		break;
	}

	cout << "Индексы элементов, значения которых больше предыдущих\n";

	ShowIndex(array, size);

	if (CheckElement(array, size))
		cout << "существует две пары соседних элементов с одинаковыми знаками\n";
	else
		cout << "не существует две пары соседних элементов с одинаковыми знаками\n";

	MinToAverage(array, size);
	cout << arrayToString(array, size, "Измененный массив = ") << '\n';

	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
}

void randomizeArray(int* array, const size_t size, const int min, const int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	const uniform_int_distribution<> uniformIntDistribution(min, max);

	for (size_t i = 0; i < size; ++i)
		array[i] = uniformIntDistribution(gen);

}

void userInput(int* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> array[i];
	}
}

string arrayToString(int* array, const size_t size, const string& message = "")
{
	stringstream str;
	str << message << "{" << array[0];

	for (size_t i = 1.0; i < size; ++i)
	{
		str << ", " << array[i];
	}

	str << "}";

	return
		str.str();
}

size_t GetMin(int* array, size_t size) {
	size_t minIndex = 0;

	for (size_t i = 1.0; i < size; i++)
	{
		if (array[minIndex] > array[i])
			minIndex = i;
	}

	return minIndex;
}

int GetAverage(int* array, size_t size) {
	int average = 0;
	for (size_t i = 1.0; i < size; i++) {
		average += array[i];
	}
	return average / int (size);
}

void MinToAverage(int* array, size_t size)
{
	array[GetMin(array, size)] = GetAverage(array, size);
}

void ShowIndex(int* array, size_t size) {
	if (size <= 2)
		return;

	for (size_t i = 1.0; i < size - 1; i++)
	if (array[i] < array[i + 1])
		cout << "index = " << i + 1 << '\n';

}

bool CheckElement(int* array, size_t size) {
	int k = 0;

	for (size_t i = 0; i < size; i++)
	if (array[i] * array[i + 1] > 0)
		k++;
	return k >= 2;
}
