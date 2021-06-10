#include <iostream>
#include <map>
#include <list>
using std::cout;
using std::endl;
using std::cin;

//map,set,multimap,multiset

#define tab "\t"
#define MAP

void main()
{
	setlocale(LC_ALL, "RU");
#ifdef MAP
	/*std::map<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(6, "Saturday"),
	};
	for (std::map<int,std::string>:: iterator it = week.begin();it!=week.end();it++)
	{
		cout << it->first << tab << it->second << endl;
	}*/
	std::map<std::string, std::list<std::string>> dictionary 
	{
		std::pair < std::string, std::list<std::string>>("finite", {"ограниченный", "имеющий предел"}),
		std::pair < std::string, std::list<std::string>>("adjacent", {"примыкающий", "соседний","соседний"}),
		std::pair < std::string, std::list<std::string>>("plot", {"карта", "план","график","сюжет"}),
		std::pair < std::string, std::list<std::string>>("incident", {"случайность", "проишествие"}),
		std::pair < std::string, std::list<std::string>>("splice", {"соединение", "сращивание"}),
	};

	cout << dictionary["finite"].front() << endl;
	dictionary["space"].assign({ "пространство", "космос", "пробел" });

	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << ":";
		cout.width(18);
		for (std::list<std::string>::iterator jt = it->second.begin();jt!=it->second.end();jt++)
		{
			cout << *jt << ", ";
		}
		cout << endl;
	}
	dictionary.find("finite")->first;
	for (std::string i : dictionary.find("finite")->second)cout << i << tab; cout << endl;
#endif // MAP

}