#include "Header.h"
//Operators overload
ForwardList operator+(const ForwardList left, const ForwardList right)
{
	ForwardList result = left;
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
uint ForwardList::get_size()const
{
	return size;
}
const Element* ForwardList::get_head() const
{
	return Head;
}
//Methods
Iterator ForwardList::begin()
{
	return Head;
}
Iterator ForwardList::end()
{
	return nullptr;
}
//Constructors
ForwardList::ForwardList()
{

	this->size = 0;
	this->Head = nullptr;
#ifdef DEBUG
	cout << "ListCtor:\t" << this << endl;
#endif // DEBUG

}
ForwardList::ForwardList(const std::initializer_list<int>& il) :ForwardList()
{
#ifdef DEBUG
	cout << typeid(il.begin()).name() << endl;
#endif // DEBUG

	for (const int* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
	/*for (int i : il)
	{
		push_back(i);
	}*/
}
ForwardList::ForwardList(const ForwardList& other) :ForwardList() //copyCtor
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
ForwardList::ForwardList(ForwardList&& other)noexcept
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
ForwardList::~ForwardList()
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
void ForwardList::push_front(int Data)
{
	Element* New = new Element(Data);
	New->pNext = Head;
	Head = New;
	size++;
};
void ForwardList::push_back(int Data)
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
void ForwardList::insert(int Index, int Data)
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
void ForwardList::pop_front()
{
	//1)Запоминаем адрес удаляемого элемента
	Element* erase_element = Head;
	//2)Исключаем элемент из списка
	Head = Head->pNext; //исключает элемент из списка
	//3) Удаляем элемент из памяти
	delete erase_element;
	size--;
}
void ForwardList::pop_back()
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
void ForwardList::erase(int index)
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
ForwardList& ForwardList::operator=(const ForwardList& other)
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
ForwardList& ForwardList::operator=(ForwardList&& other)noexcept
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
int& ForwardList::operator[](int index)
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
void ForwardList::print()const
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