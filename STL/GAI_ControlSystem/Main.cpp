#include <iostream>
#include <algorithm>
#include <map>
#include<list>
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;

#define tab "\t";
#define DELIMITER "---------------------------------------------------------------------------------------------\n";
//#define PRINT_BASE
//#define PRINT_BY_NUMBER
//#define PRINT_BY_RANGE

int MaxValue(std::map<int, std::list<std::string>> base)
{
	int max_number = 0;
	for (std::map<int, std::list<std::string>>::iterator max_value = base.begin(); max_value != base.end(); max_value++)
	{
		if (max_value->first > max_number)
		{
			max_number == max_value->first;
		}
	}
	return max_number;
}
void PrintBase(std::map<int, std::list<std::string>> base) 
{
	for (std::map<int, std::list<std::string>>::iterator it_base = base.begin(); it_base != base.end(); it_base++)
	{
		cout << "|Номер: " << it_base->first << "| - " << "|Нарушения: ";
		for (std::list<std::string>::iterator it_list = it_base->second.begin(); it_list != it_base->second.end(); it_list++)
		{
			cout <<"|"<< it_list->data()<<"|";
		};

		cout << "  |" << endl;
		cout << DELIMITER;
	}	
	
};
void PrintByNumber(std::map<int,std::list<std::string>> base, int number)
{
	for (std::map<int, std::list<std::string>>::iterator it_base = base.begin(); it_base != base.end(); it_base++)
	{
		if (it_base->first == number)
		{
			cout << "|Номер: " << it_base->first << "| - " << "|Нарушения: ";
			for (std::list<std::string>::iterator it_list = it_base->second.begin(); it_list != it_base->second.end(); it_list++)
			{
				cout << "|" << it_list->data() << "|";
			}
			cout << "  |" << endl;
			return;
		}
	}

	cout << "Номера нет в базе!";
}
void PrintByRange(std::map<int, std::list<std::string>> base, int range_Begin, int range_End)
{

	if (range_Begin<0||range_End<0)
	{
		cout << "Некорректные значения";
		return;
	}
	if (range_Begin==range_End)
	{
		cout << "Некорректный диапазон" << endl;
		return;
	}
	//Проверка на корректность диапазона номеров
	if (range_Begin>range_End)
	{
		std::swap(range_Begin, range_End);
	}
	//Вычисление элемента range_Begin;
	std::map<int, std::list<std::string>>::iterator it_range_Begin = base.lower_bound(range_Begin);
	//Вычисление элемента range_End;
	std::map<int, std::list<std::string>>::iterator it_range_End;
	//it_range_End++;
	if (MaxValue(base)<range_End)
	{
		it_range_End = base.find(MaxValue(base));
	}
	else
	{
		it_range_End = base.upper_bound(range_End);
	}
	//Вывод
	for (std::map<int, std::list<std::string>>::iterator it = it_range_Begin; it!= it_range_End; it++)
		{
			cout << "|Номер: " << it->first << "| - " << "|Нарушения: ";
			for (std::list<std::string>::iterator it_second = it->second.begin(); it_second != it->second.end(); it_second++)
			{
				cout << "|" << it_second->data() << "|";
			};
			cout << "  |" << endl;
			cout << DELIMITER;
		}

}


void main()
{
	setlocale(LC_ALL, "RU");
	std::map<int, std::list<std::string>> Base;
	Base.insert(std::pair<uint, std::list<std::string>>(1, { "Превышение", "Неправильная парковка" }));
	Base.insert(std::pair<uint, std::list<std::string>>(2, { "Просроченная страховка", "Езда без документов" }));
	Base.insert(std::pair<uint, std::list<std::string>>(3, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<uint, std::list<std::string>>(4, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<uint, std::list<std::string>>(5, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<uint, std::list<std::string>>(6, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<uint, std::list<std::string>>(7, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<uint, std::list<std::string>>(8, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<uint, std::list<std::string>>(9, { "Обгон на сплошной", "Авария" }));
#ifdef PRINT_BASE
	PrintBase(Base);
#endif // PRINT_BASE
#ifdef PRINT_BY_NUMBER

	int number;
	cout << "Введите номер для поиска в базе: "; cin >> number;
	PrintByNumber(Base, number);
#endif // PRINT_NY_NUMBER
#ifdef PRINT_BY_RANGE
	uint range_Begin, range_End;
	cout << "Введите начало диапазона номеров для вывода: "; cin >> range_Begin;
	cout << "Введите конец диапазона номеров для вывода: "; cin >> range_End;
	PrintByRange(Base, range_Begin, range_End);
#endif // PRINT_BY_RANGE

}