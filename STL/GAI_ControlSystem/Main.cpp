#include <iostream>
#include <algorithm>
#include <map>
#include<list>
#include<Windows.h>
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;

#define tab "\t";
#define DELIMITER "---------------------------------------------------------------------------------------------\n";
#define PRINT_BASE
//#define PRINT_BY_NUMBER
//#define PRINT_BY_RANGE
//#define ADD_NEW

int MaxValue(std::map<int, std::list<std::string>> base)
{
	int max_number = 0;
	for (std::map<int, std::list<std::string>>::iterator max_value = base.begin(); max_value != base.end(); max_value++)
	{
		if (max_value->first > max_number)
		{
			max_number = max_value->first;
		}
	}
	return max_number;
}
void PrintBase(std::map<int, std::list<std::string>> base) 
{
	for (std::map<int, std::list<std::string>>::iterator it_base = base.begin(); it_base != base.end(); it_base++)
	{
		cout << DELIMITER;
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
			cout << DELIMITER;
			cout << "|Номер: " << it_base->first << "| - " << "|Нарушения: ";
			for (std::list<std::string>::iterator it_list = it_base->second.begin(); it_list != it_base->second.end(); it_list++)
			{
				cout << "|" << it_list->data() << "|";
			}
			cout << "  |" << endl;
			cout << DELIMITER;
			return;
		}
	}

	cout << "Номера нет в базе!\n";
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
			cout << DELIMITER;
			cout << "|Номер: " << it->first << "| - " << "|Нарушения: ";
			for (std::list<std::string>::iterator it_second = it->second.begin(); it_second != it->second.end(); it_second++)
			{
				cout << "|" << it_second->data() << "|";
			};
			cout << "  |" << endl;
			cout << DELIMITER;
		}

}
void Add(std::map<int, std::list<std::string>>& base, int car_number, std::string violation)
{
	bool already_in_base = false;

	for (std::map<int, std::list<std::string>>::iterator it = base.begin();it!=base.end();it++)
	{
		if (it->first==car_number)
		{
			already_in_base = true;
			break;
		}
	}

	if (already_in_base == false)
	{
		base.insert(std::pair<int, std::list<std::string>>(car_number, { violation }));
	}

	else
	{
		base[car_number].assign({ violation });
	}
}


void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::map<int, std::list<std::string>> Base;
	Base.insert(std::pair<int, std::list<std::string>>(118, { "Превышение", "Неправильная парковка" }));
	Base.insert(std::pair<int, std::list<std::string>>(253, { "Просроченная страховка", "Езда без документов" }));
	Base.insert(std::pair<int, std::list<std::string>>(200, { "Езда по тротуару", "Авария" }));
	Base.insert(std::pair<int, std::list<std::string>>(655, { "Авария", "Превышение" }));
	Base.insert(std::pair<int, std::list<std::string>>(598, { "Обгон на сплошной", "Авария" }));
	Base.insert(std::pair<int, std::list<std::string>>(636, { "Езда по тротуару", "Авария" }));
	Base.insert(std::pair<int, std::list<std::string>>(111, { "Обгон на сплошной", "Превышение" }));
	Base.insert(std::pair<int, std::list<std::string>>(822, { "Езда без документов", "Обгон на сплошной" }));
	Base.insert(std::pair<int, std::list<std::string>>(156, { "Обгон на сплошной", "Авария" }));
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
#ifdef ADD_NEW
	int car_number;
	cout << "Введите номер автомобиля: "; cin >> car_number;
	std::string violation;
	cout << "Введите нарушение: "; cin >> violation;
	Add(Base, car_number, violation);
	PrintBase(Base);
#endif // ADD_NEW


}