#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;
#define tab "\t"
#define delimiter "----------------------------------------------------\n";

class List
{
public:
	class Element
	{
	private:
		int Data;
		Element* pPrev;
		Element* pNext;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			this->pPrev = pPrev;
			cout << "ECtor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDeCtor:\t" << this << endl;
		}
		friend class List;
	};
	Element* Head;
	Element* Tail;
	uint size;
//Constructors
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LCtor:\t" << this << endl;
	}
	List(const List& other):List()//copy Ctor
	{
		for (Element* Temp = other.Head; Temp ; Temp=Temp->pNext)
		{
			PushBack(Temp->Data);
		}
		cout << "CopyCtor:\t" << this << endl;
	}
	~List()
	{
		// смотря какая функция используется

		/*while (Head) 
		{
			PopBack();
		}*/

		while(Tail)
		{
			PopBack();
		}
		cout << "LDeCtor:\t" << this << endl;
	}
//Operators overload
	List& operator=(const List& other)
	{
		if (this==&other)
		{
			return *this;
		}
		while (Head)
		{
			PopFront();
		}
		for (Element* Temp = other.Head; Temp; Temp=Temp->pNext)
		{
			PushBack(Temp->Data);
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
		
	}
//Adding Elements
	void PushFront(int Data)
	{
		if (Head==nullptr&&Tail==nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void PushBack(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;
	}
	void Insert(int Index, int Data)
	{
		if (Index>size)
		{
			return;
		}
		if (Index==size)
		{
			PushBack(Data);
			return;
		}
		if (Index==0)
		{
			PushFront(Data);
			return;
		}
		Element* Temp;
		if (Index<size/2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)
				Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size-Index-1; i++)
			{
				Temp = Temp->pPrev;
			}
		}
		Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;
		size++;
	}
//Delete Elements
	void PopFront()
	{
		if (Head == Tail)
		{
			size--;
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void PopBack()
	{
		if (Head == Tail)
		{
			size--;
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void Erase(int Index)
	{
		if (Index > size)
		{
			return;
		}
		if (Index == size-1)
		{
			PopBack();
			return;
		}
		if (Index == 0)
		{
			PopFront();
			return;
		}
		Element* Temp;
		if (Index<size/2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)
			{
				Temp = Temp->pNext;
			}
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size-Index-1; i++)
			{
				Temp = Temp->pPrev;
			}
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}
//Methods
	void Print()
	{
		for (Element* Temp=Head;Temp;Temp=Temp->pNext)
		{
			cout << Temp << endl << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size <<endl;
	}
	void PrintRevers()
	{
		for (Element*Temp=Tail;Temp; Temp=Temp->pPrev)
		{
			cout << Temp << endl << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;
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
		list.PushBack(rand() % 100 + 10);
	}
	list.Print();
	cout << delimiter;
	cout << delimiter;
	List list2;
	list2 = list;
	list2.Print();
	

}