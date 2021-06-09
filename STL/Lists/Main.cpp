#include<iostream>
#include <list>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

template<typename T>void list_properties(const std::list<T>& lst)
{
	cout << "Size:  " << lst.size() << endl;
	cout << "MaXSize:  " << lst.max_size() << endl;

}
template<typename T>void print_list(const std::list<T>& lst)
{
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << tab;
	}
}


void main()
{
	setlocale(LC_ALL, "RU");
	std::list<int> lst = {3,5,8,13,21,};
	list_properties(lst);
	print_list(lst);
	cout << endl;
	lst.push_front(2);
	lst.push_back(34);
	print_list(lst);
	list_properties(lst);

}