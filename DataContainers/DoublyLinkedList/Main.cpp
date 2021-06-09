#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
typedef unsigned int uint;
#define tab "\t"
<<<<<<< HEAD

class Element
{
private:
	int Data; // ÁÌ‡˜ÂÌËÂ
	Element* pNext; //ÛÍ‡Á‡ÚÂÎ¸ Ì‡ ÒÎÂ‰Û˛˘ËÈ ˝ÎÂÏÂÌÚ
	Element* pPrew; //ÛÍ‡Á‡ÚÂÎ¸ Ì‡ ÔÂ‰˚‰Û˘ËÈ ˝ÎÂÏÂÌÚ
	static int count; //Ò˜ÂÚ˜ËÍ
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
=======
#define delimiter "----------------------------------------------------\n";
class List
{
public:
	//inner classes
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
		friend List operator+(const List& left, const List& right);
	};
	class Iterator
	{
	private:
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp) 
		{
			cout << "ItCtor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ItDeCtor:\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		bool operator =(const Iterator other)const
		{
			return this->Temp==other.Temp;
		}
		bool operator!=(const Iterator other)const
		{
			return this->Temp != other.Temp;
		}
		int& operator*()
		{
			return Temp->Data;
		}
		const int& operator*() const
		{
			return Temp->Data;
		}
	};
	class ReverseIterator
	{
	private:
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp) 
		{
		}
		~ReverseIterator()
		{
>>>>>>> b3b6848fe423d5a678ded7fee78672151cbf80d0

		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator& operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator& operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
		{
			return Temp->Data;
		}
		const Element* operator->()const
		{
			return Temp;
		}
		Element* operator->()
		{
			return Temp;
		}
	};
	//end of inner classes
	Element* Head;
	Element* Tail;
<<<<<<< HEAD
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
=======
	uint size;
//Constructors
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LCtor:\t" << this << endl;
>>>>>>> b3b6848fe423d5a678ded7fee78672151cbf80d0
	}
	List(const List& other):List()//copy Ctor
	{
		for (Element* Temp = other.Head; Temp ; Temp=Temp->pNext)
		{
			PushBack(Temp->Data);
		}
		cout << "CopyCtor:\t" << this << endl;
	}
	List(List&& other)noexcept //move Ctor
	{
		this->size = other.size;
		this->Head = other.Head;
		this->Tail = other.Tail;
		other.Head = nullptr;
		other.Tail = nullptr;
		cout << "MoveCtor:\t" << this <<endl;
	}
	List(int size) //Size Ctor
	{
		for (int i = 0; i < size; i++)
		{
			PushFront(NULL);
		}
	}
	List(const std::initializer_list<int>& il) :List() 
	{
		for (const int* it = il.begin(); it!=il.end() ; it++)
		{
			PushBack(*it);
		}
	}
	~List() //move ctor
	{
		// —Å–º–æ—Ç—Ä—è –∫–∞–∫–∞—è —Ñ—É–Ω–∫—Ü–∏—è –∏—Å–ø–æ–ª—å–∑—É–µ—Ç—Å—è

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
	const Iterator begin()const
	{
		return Head;
	}
	Iterator begin()
	{
		return Head;
	}
	const Iterator end() const
	{
		return nullptr;
	}
	Iterator end()
	{
		return nullptr;
	}
	const ReverseIterator rbegin()const
	{
		return Tail;
	}
	ReverseIterator rbegin()
	{
		return Tail;
	}
	const Iterator rend() const
	{
		return nullptr;
	}
	Iterator rend()
	{
		return nullptr;
	}
//Operators overload
	List& operator=(List&& other)noexcept //move assignment
	{
		while (Head)
		{
			PopFront();
		}
		this->size = other.size;
		this->Head = other.Head;
		this->Tail = other.Tail;
		cout << "MovaAssighnment:\t" <<this << endl;
	}
	List& operator=(const List& other) //copy assignment
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
	int& operator[](int index)
	{
		//if (index >= size)throw std::exception("Out of range");
		Element* Temp = Head;
		for (int count  = 0; count < index; count++)
		{
			Temp = Temp->pNext;
		}
		return Temp->Data;
		
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
<<<<<<< HEAD
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
=======
		Head->pPrev = New;
		Head = New;
		size++;
		//optimization code
		//Head = Head->pPrev = new Element(Data, Head);
	}
	void PushBack(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
>>>>>>> b3b6848fe423d5a678ded7fee78672151cbf80d0
		}
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;*/
		//optimization code
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
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
		//optimization code
		//Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
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
		cout << "–ö–æ–ª–∏—á–µ—Å—Ç–≤–æ —ç–ª–µ–º–µ–Ω—Ç–æ–≤ —Å–ø–∏—Å–∫–∞: " << size <<endl;
	}
	void PrintRevers()
	{
		for (Element*Temp=Tail;Temp; Temp=Temp->pPrev)
		{
			cout << Temp << endl << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "–ö–æ–ª–∏—á–µ—Å—Ç–≤–æ —ç–ª–µ–º–µ–Ω—Ç–æ–≤ —Å–ø–∏—Å–∫–∞: " << size << endl;
	}
	friend List operator+(const List& left, const List& right);
	friend class Iterator;
	friend class ReverseIterator;
};

List operator+(const List& left, const List& right)
{
	List result = left;
	//for (List::Element* Temp = right.Head;Temp;Temp=Temp->pNext)
	//{
	//	result.PushBack(Temp->Data);
	//}
	for (List::Iterator it = right.begin(); it!=right.end();it++)
	{
		result.PushBack(*it);
	}
	return result;
}
//#define BASE_CHECK
//#define COPY_METHODS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define ITERATOR_CHECK


void main()
{
	setlocale(LC_ALL, "RU");
#ifdef BASE_CHECK
	int n;
	cout << "–í–≤–µ–¥–∏—Ç–µ —Ä–∞–∑–º–µ—Ä —Å–ø–∏—Å–∫–∞: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
<<<<<<< HEAD
		list.PushFront(rand() % 100 + 10);
	}
	list.Print();
=======
		list.PushBack(rand() % 100 + 10);
	}
	list.Print();
#endif // BASE_CHECK
#ifdef COPY_METHODS_CHECK
	List list;
	list.PushBack(3);
	list.PushBack(5);
	list.PushBack(8);
	list.PushBack(13);
	list.PushBack(21);
	List list2 = list;
#endif // COPY_METHODS_CHECK
#ifdef OPERATOR_PLUS_CHECK
	List list1 = { 3,5,8,13,21 };
	List list2 = { 34,55,89 };
	List list3 = list1 + list2; //move method
	list3.Print();

#endif // OPERATOR_PLUS_CHECK
#ifdef ITERATOR_CHECK
	List list = { 3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << endl;
	}
	cout << endl;
#endif // ITERATOR_CHECK
	List list = { 3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << endl;
	}
	cout << endl;






	
>>>>>>> b3b6848fe423d5a678ded7fee78672151cbf80d0

}