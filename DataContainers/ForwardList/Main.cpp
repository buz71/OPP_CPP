#include <iostream>
#include <stdarg.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define DELIMITER "---------------------------------------------------"
//#define DEBUG
typedef unsigned int uint;
class Element
{
private:
	int Data; //Значение элемента
	Element* pNext; //Указатель на следующий элемент
	static int count;
public:
	const Element* get_pNext() const
	{
		return pNext;
	}
	const int get_Data()const
	{
		return Data;
	}
	void set_pNext(Element* pNext)
	{
		this->pNext = pNext;
	}
	explicit Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		//cout << "ECtor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		//cout << "EDeCtor:\t" << this << endl;
#endif // DEBUG

	}
	friend class ForwardList; 
	friend ForwardList operator+(const ForwardList left, const ForwardList right);
};
int Element::count = 0;
class ForwardList
{
private:
	uint size;
	Element* Head; //Указатель на начальный элемент списка
public:
	uint get_size()const
	{
		return size;
	}
	const Element* get_head() const
	{
		return Head;
	}
	//Constructors
	explicit ForwardList()
	{

		this->size = 0;
		this->Head = nullptr;
#ifdef DEBUG
		cout << "ListCtor:\t" << this << endl;
#endif // DEBUG

	}
	ForwardList(const std::initializer_list<int>&il):ForwardList()
	{
#ifdef DEBUG
		cout << typeid(il.begin()).name() << endl;
#endif // DEBUG

		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
#ifdef DEBUG
		cout << "IlCtor:\t" << this << endl;
#endif // DEBUG

	}
	ForwardList(const ForwardList& other):ForwardList() //copyCtor
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->Data);
		}
		// мой вариант
		/*this->Head = nullptr;
		Element* Temp = other.Head;
		while (Temp!=nullptr)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}*/
#ifdef DEBUG
		cout << "CopyCtor:\t" << this << endl;
#endif // DEBUG

	}
	ForwardList(ForwardList&& other)noexcept
	{
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		//мой вариант
		/*Element* Temp = other.Head;
		other.Head = nullptr;
		while (Temp != nullptr)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}*/
		cout << "LMoveCtor:\t" << this << endl;

	}
	~ForwardList()
	{
		Element* Temp = Head;
		while (Temp)
		{
			Temp = Temp->pNext;
			pop_front();
		}
#ifdef DEBUG
		cout << "ListDeCtor:\t" << this << endl;
#endif // DEBUG

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
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index > Element::count)
		{
			return;
		}
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
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
			while (Temp->pNext->pNext != nullptr)
				Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index >= size)
		{
			//pop_back();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* Buf = Temp->pNext->pNext;
		delete Temp->pNext;
		Temp->pNext = Buf;
		size--;
	}
	//Operators overload
	ForwardList& operator=(const ForwardList& other)
	{
		//0. Проверяем не является ли список самим собой
		if (this == &other)
		{
			return *this;
		}
		// 1.Очищаем список от старых значений
		while (Head)
		{
			pop_front();
		}
		//2. Копируем список
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		{
			push_back(Temp->Data);
		}
		return *this;

#ifdef DEBUG
			cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG
		//мой метод
		/*Element* Temp = other.Head;
		while (Temp != nullptr)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "CopyAssignment:\t" << this << endl;*/
	}
	ForwardList& operator=(ForwardList&& other)noexcept
	{
		while (Head)
		{
			pop_front();
		}
		this->size = other.size;
		this->Head = other.Head;
		other.Head = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
		//мой вариант
		/*Element* Temp = other.Head;
		other.Head = nullptr;
		while (Temp != nullptr)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "MoveAssignment:\t" << this << endl;*/

	}
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int count = 0; count < index; count++)
		{
			Temp = Temp->pNext;
		}
		return Temp->Data;
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
		while (Temp != nullptr)
		{
			cout << "Адрес: " << Temp << tab << "Data: " << Temp->Data << tab << "pNext: " << Temp->pNext << endl;
			Temp = Temp->pNext; //переход на следующий элемент
		}
		cout << "В списке " << size << " элементов\n";
		cout << "Общее кол-во элементов: " << Element::count << endl;
	}
};

//Operators overload
ForwardList operator+(const ForwardList left, const ForwardList right)
{
	ForwardList result = left;
	for (const Element* Temp = right.get_head(); Temp; Temp=Temp->get_pNext())
	{
		result.push_back(Temp->get_Data());
	}
	return result;
#ifdef DEBUG
	cout << "PlusOptor" << endl;
#endif // DEBUG

	//Мой метод
	/*ForwardList result = left;
	Element* Temp = right.get_head();
	while (Temp)
	{
		result.push_back(Temp->get_Data());
		Temp = Temp->get_pNext();
	}
	return result;*/
}


//#define adding_elements_check
//#define HOMEWORK
#define HARDCORE
//#define COPYMETHODS_CHECK
//#define OPERATOR_PLUS_CHECK
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
	ForwardList list = { 3,5,8,13,21 };
	//list.print();
	cout<<list[4];
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