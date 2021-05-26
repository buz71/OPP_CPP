#include "Element.h"
#include "Element.cpp"
#include "Iterator.h"
#include "Iterator.cpp"
#include "ForwList.h"
#include "ForwardList.cpp"

void main()
{
	setlocale(LC_ALL, "RU");
	int n;
	int value;
	int index;
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
		};
#endif // EXCEPTION
#ifdef HARDCORE
		ForwardList<int> list = { 3,5,8,13,21 };
		for (int i : list) //range-based for
		{
			cout << i << tab;
		}
		cout << endl;
#endif // HARDCORE
		ForwardList <double>dfl={ 2.5,2.87,3.14,5.9,8.2 };
		for (double i : dfl)cout << i << tab << endl;
		cout << endl;
		/*ForwardList<std::string> stih = { "Хорошо","живет","на","свете","Винни-Пух" };
		for (std::string i :stih)cout << i << tab;*/
		
};
