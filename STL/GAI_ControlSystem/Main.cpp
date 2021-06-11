#include <iostream>
#include <map>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t";
#define DELIMITER "----------------------------------------------\n";

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

void main()
{
	setlocale(LC_ALL, "RU");
	std::map<int, std::list<std::string>> Base;
	Base.insert(std::pair<int, std::list<std::string>>(0, { "Превышение", "Угон" }));
	Base.insert(std::pair<int, std::list<std::string>>(2, { "Превышение", "Угон" }));
	Base.insert(std::pair<int, std::list<std::string>>(1, { "Превышение", "Угон" }));
	PrintBase(Base);
}