#include "Header.h"
void main()
{
	setlocale(LC_ALL, "RU");
	int n;
	int value;
	int index;
#ifdef HOMEWORK
	cout << "Введите размер списка: "; cin >> n;
	cout << delimiter << endl;
	cout << "Список 1" << endl;
	cout << delimiter << endl;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back((rand() % 100) + 10);
	}
	cout << delimiter << endl;
	cout << delimiter << endl;
	list.print();
	cout << delimiter << endl;
	cout << "Список 2" << endl;
	cout << delimiter << endl;
	ForwardList list2 = list;
	cout << delimiter << endl;
	cout << delimiter << endl;
	list2.print();
	cout << delimiter << endl;
	cout << "Список 3" << endl;
	cout << delimiter << endl;
	ForwardList list3 = list + list2;
	cout << delimiter << endl;
	list3.print();
	ForwardList list4 = { 0,0,0 };
	cout << delimiter << endl;
	cout << delimiter << endl;
	cout << "Список 4" << endl;
	list4.print();
	cout << delimiter << endl;
	cout << delimiter << endl;
#endif // homework
#ifdef COPYMETHODS_CHECK
	ForwardList list;
	cout << "Введите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100 + 10);
	}
	list = list;
	list.print();
	cout << DELIMITER << endl;
	ForwardList list2;
	list2 = list;
	list2.print();
#endif // COPYMETHODS_CHECK
#ifdef OPERATOR_PLUS_CHECK
	cout << DELIMITER << endl;
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);
	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);
	list2.push_back(144);
	ForwardList list3;
	list3 = list1 + list2;
	list3.print();
	cout << DELIMITER << endl;
#endif // OPERATOR_PLUS_CHECK
#ifdef HARDCORE
#ifdef EXCEPTION
	ForwardList list = { 3,5,8,13,21 };
	try
	{
		for (int i = 0; i < list.get_size(); i++)
		{
			list[i] = rand() % 100;
		}

		for (int i = 0; i < list.get_size(); i++)
		{
			cout << list[i] << tab;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl; //метод what() возвращает сообщение об ошибке
	}
#endif // EXCEPTION
	ForwardList list = { 3,5,8,13,21 };
	for (int i : list) //range-based for
	{
		cout << i << tab;
	}
	cout << endl;
#endif // HARDCORE
#ifdef adding_elements_check
	cout << "Push_Front" << endl;
	list.print();
	/*cout << "Введите значение: "; cin >> value;
	cout << "Push_Back" << endl;
	list.push_back(value);
	list.print();
	cout << "Введите индекс "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	list.insert(index, value);
	cout << "Insert" << endl;
	list.print();*/
	ForwardList list2;
	cout << "Введите размер списка: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		list2.push_back((rand() % 100) + 10);
	}
	list2.print();
#endif // adding_elements_check





}