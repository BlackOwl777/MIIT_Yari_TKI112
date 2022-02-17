#include <string>
#include <iostream>
#include <iomanip>

/**
* \brief Считать количество членов последовательности.
* \param message Сообщение пользователю.
* \return Количество членов последовательности.
* \exception std::invalid_argument В случае количества, меньшего 1.
*/
size_t getCount(const std::string& message = "");

/**
* \brief Считать точность вычисления суммы последовательности.
* \param message Сообщение пользователю.
* \return Точность вычиcления членов последовательности.
* \exception std::invalid_argument В случае точности, меньшего или равна 0.
*/
double getEpsilon(const std::string& message = "");

/**
* \brief Рассчитывает суммму последовательности.
* \param count Количество членов последовательности.
* \return Сумма последовательности.
*/
double getSum(const size_t count);

/**
* \brief Рассчитывает суммму последовательности.
* \param epsilon Точность вычиcления членов последовательности.
* \return Сумма последовательности.
*/
double getSum(const double epsilon);


/**
* \brief Рассчитывает рекуррентный член последовательности.
* \param k Номер члена последовательности.
* \return Значение рекуррентного члена последовательности.
*/
double getRecurrent(const size_t k);

/**
* \brief Точка входа в программу.
* \return 0 в случае успеха.
*/
int main()
{
	try 
	{
		const auto count = getCount("Введите количество членов последовательности = ");
		auto sum = getSum(count);
		std::cout << std::setprecision(20) << "Сумма " << count << " членов последовательности равна " << sum << "\n";

		const auto epsilon = getEpsilon("Введите точность вычисления = ");
		sum = getSum(epsilon);
		std::cout << std::setprecision(20) << "Сумма членов последовательности с заданной точностью равна " << sum << "\n";
	}
	catch (std::invalid_argument const& ex)
	{
		std::cerr << ex.what();
		return 1;
	}

	return 0;
}

size_t getCount(const std::string& message)
{
	const auto THRESHOLD = 1;

	std::cout << message;
	auto count = THRESHOLD;
	std::cin >> count;

	if (count < THRESHOLD)
	{
		throw std::invalid_argument("Число должно быть больше " + std::to_string(THRESHOLD));
	}

	return count;
}

double getEpsilon(const std::string& message)
{
	const auto THRESHOLD = 0.0;

	std::cout << message;
	auto epsilon = 1e-5;
	std::cin >> epsilon;

	if (epsilon <= THRESHOLD)
	{
		throw std::invalid_argument("Число должно быть больше " + std::to_string(THRESHOLD));
	}

	return epsilon;
}

double getSum(const size_t count)
{
	auto current = 1.0;
	auto sum = current;

	for (size_t k = 1; k < count; k++)
	{
		current *= getRecurrent(k);
		sum += current;
	}

	return sum;
}

double getSum(const double epsilon)
{
	auto current = 1.0;
	auto sum = current;
	size_t k = 1;

	while(std::abs(current) > epsilon)
	{ 
		current *= getRecurrent(k);
		sum += current;
		k++;
	}

	return sum;
}

double getRecurrent(const size_t k)
{
	return 1.0 / (4*k*k + 6*k +2); 
}
