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
void getReplacingArray(int *arr, int size)
/**
* \brief Удаление нечетных элементов, кратных 3.
* \param arr массив.
* \param size размер массива.
* \return изменённый массив.
*/
int getOddElements(int *arr, int size)
/**
* \brief Создание нового массива по формуле
* \param arr массив.
* \param size размер массива.
* \return изменённый массив.
*/
int* getNewArray(int *arr, int size)
/**
* \brief Точка входа в программу.
* \return 0, в случае успеха.
*/
int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите размерность массива: ";
	int n;
	cin >> n;

	cout << "Выберите способ заполнения массива (1 - вручную, 2 - случаными числами): ";
	int f;
	cin >> f;

	int *SourceArray = new int[n];

	if (f == 1) {
		for (int i = 0; i < n; ++i){
			cout << "Введите элемент массива с индексом " << i << ":";
			cin >> SourceArray[i];
		}
	}
	else {
		cout << "Массив будет заполнен случайным образом" << endl;
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> dist(0, 60);

		for (int i = 0; i < n; ++i){
			SourceArray[i] = dist(rng) - 20;;
		}
	}

	cout << "Исходный массив: " << endl;
	printArray(SourceArray, n);

	getReplacingArray(SourceArray, n);
	cout << endl << "Метод1: " << endl;
	printArray(SourceArray, n);

	cout << endl << "Метод2: " << endl;
	n = getOddElements(SourceArray, n);
	printArray(SourceArray, n);

	cout << endl << "Метод3: " << endl;
	printArray(getNewArray(SourceArray, n), n);

	return 0;
}

void printArray(int arr[], int size)

{
	for (int i = 0; i < size; ++i) cout << arr[i] << ' ';
}

void getReplacingArray(int *arr, int size)
{
	int minIndex = -1;
	int minValue = 40;
	for (int i = 0; i < size; ++i) {
		if (arr[i] <= minValue and arr[i] > 0) {
			minIndex = i;
			minValue = arr[i];
		}
	}

	if (minIndex != -1 and arr[minIndex] != arr[size - 1]) {
		arr[minIndex] = arr[size - 1];
		cout << endl << "был изменен элемент с индексом " << minIndex << endl;
	}
	else {
		cout << endl << "изменений не произведено, т.к. отсутствуют положительные элементы отличные от послежнего" << endl;
	}
}

int getOddElements(int *arr, int size)
{
	int newSize = size;
	for (int i = size; i >= 0; --i) {
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

int* getNewArray(int *arr, int size)
{
	int* newArrayA = new int[size];

	for (int i = 0; i < size; ++i) {
		if (arr[i] == 0) {
			newArrayA[i] = arr[i];
		}
		else if (arr[i] % 2 != 0) {
			newArrayA[i] = arr[i] - i;
		}
		else {
			newArrayA[i] = arr[i] + i;
		}
	}

	return newArrayA;
}
