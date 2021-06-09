#include<iostream>
#include <list>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
//#define LIST_INSERT

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
	cout << endl;
}
template<typename T>void reverse_print_list(const std::list<T>& lst)
{
	for (std::list<int>::const_reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}


void main()
{
	setlocale(LC_ALL, "RU");
	std::list<int> lst = {3,5,8,13,21,};
	list_properties(lst);
	print_list(lst);
#ifdef LIST_INSERT
	lst.push_front(2);
	lst.push_back(34);
	print_list(lst);
	cout << endl;
	list_properties(lst);
	int index, value;
	cout << "¬ведите индекс: "; cin >> index;
	cout << "¬ведите значение: "; cin >> value; */
		std::list<int>::iterator position = lst.begin();
	for (int i = 0; i < index; i++)position++;
	lst.insert(position, value);
	print_list(lst);
	cout << endl;
#endif // LIST_INSERT
	reverse_print_list(lst);

}