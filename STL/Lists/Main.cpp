#include<iostream>
#include <list>
#include <forward_list>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define DELIMITER "---------------------------------------------------------------------------------"
//#define LIST_INSERT
//#define UNIQUE
//#define MERGE
#define FORWARD_LIST

template<typename T>void list_properties(const std::list<T>& lst)
{
	cout << "Size:  " << lst.size() << endl;
	cout << "MaXSize:  " << lst.max_size() << endl;
};
template<typename T>void print_list(const std::list<T>& lst)
{
	if (lst.empty())
	{
		cout << "List is empty";
		return;
	}
	for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
};
template<typename T>void reverse_print_list(const std::list<T>& lst)
{
	for (std::list<int>::const_reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
};


void main()
{
	setlocale(LC_ALL, "RU");
	std::list<int> lst1 = {3,5,8,13,21,};
	std::list<int> lst2 = { 34,55,89};
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
#ifdef UNIQUE
	cout << DELIMITER << endl;
	for (int i : lst)cout << i << tab; cout << endl;
	cout << DELIMITER <<endl;
	lst.unique();
	for (int i:lst )cout << i << tab; cout << endl;
	cout << DELIMITER << endl;
#endif // UNIQUE
#ifdef MERGE
	lst1.merge(lst2);
	cout << DELIMITER << endl;
	print_list(lst1);
	print_list(lst2);
	cout << DELIMITER << endl;
#endif // MERGE
#ifdef FORWARD_LIST
	std::forward_list<int> flst = { 3,5,8,13,21 };
	flst.push_front(34);
	for (std::forward_list<int>:: iterator it = flst.begin(); it!=flst.end();it++ )
	{
		cout << *it<<tab;
	}
	cout << endl;
	int index, value;
	cout << "Enter index: "; cin >> index;
	cout << "Enter value: "; cin >> value;
	std::forward_list<int>::iterator position = flst.before_begin();
	for (int i=0;i<index;i++)
	{
		position++;
	}

	flst.insert_after(position, value);

	for (int i:flst)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // FORWARD_LIST




}