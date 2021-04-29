#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "---------------------------------------------------"
typedef unsigned int uint;
class Element
{
private:
	int Data; //Значение элемента
	Element* pNext; //Указатель на слудующий элемент
	static int count;
public:
	Element(int Data,Element* pNext = nullptr):Data(Data),pNext(pNext)
	{
		count++;
		cout << "ECtor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDeCtor:\t" << this << endl;
	}
friend class ForwardList;
};
int Element::count = 0;
class ForwardList
{
private:
	uint size;
	Element* Head; //Указатель на начальный элемент списка
public:
	ForwardList()
	{
		this->size = 0;
		this->Head = nullptr;
		cout << "ListCtor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "ListDeCtor:\t" << this << endl;
	}
	//Adding elements:
	void push_front(int Data) 
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	};
	void push_back(int Data)
	{
		if (Head==nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext!=nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index>Element::count)
		{
			return;
		}
		if (Index==0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)
		{
			Temp = Temp->pNext;
		}
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	//Removing elements
	void pop_front()
	{
		//1)Запоминаем адрес удаляемого элемента
		Element* erase_element = Head;
		//2)Исключаем элемент из списка
		Head = Head->pNext; //исключает элемент из списка
		//3) Удаляем элемент из памяти
		delete erase_element;
		size--;
	}
	void pop_back() 
	{
		Element* Temp = Head;
		{
		while (Temp->pNext->pNext!=nullptr)
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index==0)
		{
			pop_front();
			return;
		}
		if (index>=size)
		{
			//pop_back();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* Buf = Temp->pNext->pNext;
		delete Temp->pNext;
		Temp->pNext=Buf;
		size--;
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
			cout <<"Адрес: " <<Temp<< tab <<"Data: "<< Temp->Data << tab <<"pNext: "<< Temp->pNext << endl;
			Temp = Temp->pNext; //переход на следующий элемент
		}
		cout << "В списке " << size << " элементов\n";
		cout << "Общее кол-во элементов: " << Element::count << endl;
	}
};
//#define adding_elements_check
void main()
{
	setlocale(LC_ALL, "RU");
	int n;
	int value;
	int index;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back((rand() % 100) + 10);
	}
	cout << delimiter << endl;
	list.print();
	cout << delimiter << endl;
	cout << "Введите индекс: "; cin >> index;
	list.erase(index);
	list.print();


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