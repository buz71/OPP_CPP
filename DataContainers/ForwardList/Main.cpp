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
template<typename T>
class Iterator;
template <typename T>
class ForwardList;

template <typename T>
class Element
{
private:
	T Data; //Значение элемента
	Element* pNext; //Указатель на следующий элемент
	static int count;
public:
	const Element* get_pNext() const
	{
		return pNext;
	}
	const T get_Data()const
	{
		return Data;
	}
	void set_pNext(Element* pNext)
	{
		this->pNext = pNext;
	}
	explicit Element(T Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
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
	friend class ForwardList<T>; 
	friend class Iterator<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};
template<typename T>
int Element<T>::count = 0;

template<typename T>
class Iterator
{
private:
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr) :Temp(Temp)
	{

	}
	~Iterator()
	{
	}
	//operators overload
	Iterator<T>& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator<T>& operator++(int)
	{
		Iterator<T> old = *this;
		Temp = Temp->pNext;
		return old;
	}
	bool operator==(const Iterator<T>& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator<T>& other)const
	{
		return this->Temp != other.Temp;
	}
	const T& operator*()const
	{
		return Temp->Data;
	}
	const Element<T>* operator->()const
	{
		return Temp;
	}
	Element<T>* operator->()
	{
		return Temp;
	}
};

template<typename T>
class ForwardList
{
private:
	uint size;
	Element<T>* Head; //Указатель на начальный элемент списка
public:
	uint get_size()const
	{
		return size;
	}
	const Element<T>* get_head() const
	{
		return Head;
	}
	//Methods
	Iterator<T> begin()
	{
		return Head;
	}
	Iterator<T> end()
	{
		return nullptr;
	}
	//Constructors
	explicit ForwardList()
	{

		this->size = 0;
		this->Head = nullptr;

	}
	ForwardList(const std::initializer_list<T>& il) :ForwardList()
	{

		//cout << typeid(il.begin()).name() << endl;

		for (const T* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList<T>(const ForwardList<T> &other) : ForwardList() //copyCtor
		{
			for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			{
				push_back(Temp->Data);
			}
		}
	ForwardList(ForwardList && other)noexcept
		{
			this->size = other.size;
			this->Head = other.Head;
			other.Head = nullptr;
			cout << "LMoveCtor:\t" << this << endl;

		}
	~ForwardList()
		{
			Element<T>* Temp = Head;
			while (Temp)
			{
				Temp = Temp->pNext;
				pop_front();
			}

		}
	//Adding elements:
	void push_front(T Data)
		{
			Element<T>* New = new Element<T>(Data);
			New->pNext = Head;
			Head = New;
			size++;
		};
	void push_back(T Data)
		{
			if (Head == nullptr)
			{
				push_front(Data);
				return;
			}
			Element<T>* New = new Element<T>(Data);
			Element<T>* Temp = Head;
			while (Temp->pNext != nullptr)
			{
				Temp = Temp->pNext;
			}
			Temp->pNext = New;
			size++;
		}
	void insert(int Index, T Data)
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
			Element<T>* New = new Element(Data);
			Element<T>* Temp = Head;
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
			Element<T>* erase_element = Head;
			//2)Исключаем элемент из списка
			Head = Head->pNext; //исключает элемент из списка
			//3) Удаляем элемент из памяти
			delete erase_element;
			size--;
		}
	void pop_back()
		{
			Element<T>* Temp = Head;
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
	ForwardList& operator=(const ForwardList & other)
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
			for (Element<T>* Temp = other.Head; Temp; Temp = Temp->pNext)
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
	ForwardList<T>& operator=(ForwardList<T> && other)noexcept
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
		}
	T& operator[](int index)
		{
			if (index >= size)throw std::exception("Out of range"); // Бросить исключение
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
			//while (Temp != nullptr)
			//{
			//	cout << "Адрес: " << Temp << tab << "Data: " << Temp->Data << tab << "pNext: " << Temp->pNext << endl;
			//	Temp = Temp->pNext; //переход на следующий элемент
			//}
			for (Iterator Temp = Head; Temp != nullptr; Temp++)
			{
				cout << *Temp << tab;
				//cout << "Адрес: " << Temp << tab << "Data: " << Temp->Data << tab << "pNext: " << Temp->pNext << endl;
			}
			cout << "В списке " << size << " элементов\n";
			cout << "Общее кол-во элементов: " << Element::count << endl;
		}
	};

	//Operators overload
	template <typename T>
	ForwardList<T>& operator+(const ForwardList<T>& left, const ForwardList<T>& right)
	{
		ForwardList<T> result = left;
		for (const Element* Temp = right.get_head(); Temp; Temp = Temp->get_pNext())
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

//#define HARDCORE
//#define EXCEPTION

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
		ForwardList<std::string> stih = { "Хорошо","живет","на","свете","Винни-Пух" };
		for (std::string i :stih)cout << i << tab;
		
	
};
