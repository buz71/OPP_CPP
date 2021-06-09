#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;
#define tab "\t"

class Element
{
private:
	int Data; // значение
	Element* pNext; //указатель на следующий элемент
	Element* pPrew; //указатель на предыдущий элемент
	static int count; //счетчик
public:
	explicit Element(int Data, Element* pNext = nullptr, Element* pPrew = nullptr):Data(Data),pNext(pNext),pPrew(pPrew)
	{
		count++;
		cout << "ElementCtor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "ElementDeCtor:\t" << this << endl;
	}
	friend class DLinkedList;
};
int Element::count = 0;

class DLinkedList 
{
private:
	uint size;
	Element* Head;
	Element* Tail;
public:
//Accessors+Mutators
	Element* get_Head()
	{
		return Head;
	}
//Ctors
	explicit DLinkedList()
	{
		this->size = 0;
		this->Head = nullptr;
		this->Tail = nullptr;
		cout << "ListCtor:\t" << this << endl;
	}
	~DLinkedList()
	{
		cout << "ListDeCtor:\t" << this << endl;
	}
//Methods
	void PushFront(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		New->pPrew = 
		Head = New;
		size++;
	};
	void PushBack(int Data)
	{
		if (Head==nullptr)
		{
			PushFront(Data);
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
	void Print()const
	{
		Element* Temp = Head;
		for (; Temp !=nullptr; Temp=Temp->pNext)
		{
			cout <<"Data: "<< Temp->Data<<tab <<"pNext:"<<Temp->pNext<<tab<<"pPrew:"<<Temp->pPrew << endl;
		}
	}
	
};


void main()
{
	setlocale(LC_ALL, "RU");
	int n;
	cout << "¬ведите размер списка: "; cin >> n;
	DLinkedList list;
	for (int i = 0; i < n; i++)
	{
		list.PushFront(rand() % 100 + 10);
	}
	list.Print();

}