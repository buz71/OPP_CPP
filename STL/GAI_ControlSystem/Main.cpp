#include <iostream>
#include <map>
#include<list>
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;

#define tab "\t";
#define DELIMITER "---------------------------------------------------------------------------------------------\n";

void PrintBase(std::map<uint, std::list<std::string>> base) 
{
	for (std::map<uint, std::list<std::string>>::iterator it_base = base.begin(); it_base != base.end(); it_base++)
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
void PrintByNumber(std::map<uint,std::list<std::string>> base, uint number)
{
	for (std::map<uint, std::list<std::string>>::iterator it_base = base.begin(); it_base != base.end(); it_base++)
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

void main()
{
	setlocale(LC_ALL, "RU");
	std::map<uint, std::list<std::string>> Base;
	Base.insert(std::pair<uint, std::list<std::string>>(1, { "Превышение", "Неправильная парковка" }));
	Base.insert(std::pair<uint, std::list<std::string>>(2, { "Просроченная страховка", "Езда без документов" }));
	Base.insert(std::pair<uint, std::list<std::string>>(3, { "Обгон на сплошной", "Авария" }));
	//PrintBase(Base);
	int number;
	cout << "Введите номер для поиска в базе: "; cin >> number;
	PrintByNumber(Base,number);
}