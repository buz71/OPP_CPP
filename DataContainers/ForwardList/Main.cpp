#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
class Element
{
private:
	int Data; //Значение элемента
	Element* pNext; //Указатель на слудующий элемент
public:
	Element(int Data,Element* pNext = nullptr):Data(Data),pNext(pNext)
	{
		cout << "ECtor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDeCtor:\t" << this << endl;
	}
friend class List;
};
class List
{
private:
	Element* Head; //Указатель на начальный элемент списка
	int size = 0;
public:
	List()
	{
		this->Head = nullptr;
		cout << "ListCtor:\t" << this << endl;
	}
	~List()
	{
		cout << "ListDeCtor:\t" << this << endl;
	}
	//Adding elements:
	void push_front(int Data) 
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
	};
	void push_back(int Data)
	{
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext!=nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		
	}
	//Methods
	void print()const
	{
		//Для того чтобы ходить по списку нужны:
		//1. - Итератор
		//2. - Цикл
		Element* Temp = Head;
		//Temp - это итератор
		// Итератор - это указатель, при  помощи которого можно получить доступ к элементам структуры данных.
		while (Temp!=nullptr)
		{
			cout <<"Адрес: " <<Temp << tab <<"Data: "<< Temp->Data << tab <<"pNext: "<< Temp->pNext << endl;
			Temp = Temp->pNext; //переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "RU");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	cout << "Push_Back" << endl;
	list.push_back(rand() % 100);
	list.print();
}