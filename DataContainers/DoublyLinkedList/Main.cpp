#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;

class Element
{
private:
	Element* pNext;
	Element* pPrew;
	int Data;
	static int count;
public:
	explicit Element(int Data, Element* pNext = nullptr, Element* pPrew = nullptr)
	{
		count++;
	}
	~Element()
	{
		count--;
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
	explicit DLinkedList()
	{
		this->size = 0;
		this->Head = nullptr;
		this->Tail = nullptr;
	}
//Methods
	void PushFront(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	};
	void Print()const
	{
		for (Element* Temp = Head;Temp!=nullptr; Temp=Temp->pNext)
		{
			cout << Temp->Data << endl;
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
		list.PushFront((rand() % 100) + 10);
	}

}