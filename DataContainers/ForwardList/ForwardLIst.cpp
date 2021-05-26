#include "ForwList.h"
//class realisation ForwardList
template <typename T>uint ForwardList<T>::get_size()const
{
	return size;
}
template <typename T>const Element<T>* ForwardList<T>::get_head() const
{
	return Head;
}
//Methods
template <typename T>Iterator<T> ForwardList<T>::begin()
{
	return Head;
}
template <typename T>Iterator<T> ForwardList<T>::end()
{
	return nullptr;
}
//Constructors
template <typename T>ForwardList<T>::ForwardList()
{

	this->size = 0;
	this->Head = nullptr;

}
template <typename T>ForwardList<T>::ForwardList(const std::initializer_list<T>& il) :ForwardList()
{

	//cout << typeid(il.begin()).name() << endl;

	for (const T* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
};
template <typename T>ForwardList<T>::ForwardList(const ForwardList<T>& other) : ForwardList() //copyCtor
{
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
	{
		push_back(Temp->Data);
	}
};
template <typename T>ForwardList<T>::ForwardList(ForwardList&& other)noexcept
{
	this->size = other.size;
	this->Head = other.Head;
	other.Head = nullptr;
	cout << "LMoveCtor:\t" << this << endl;

}
template <typename T>ForwardList<T>::~ForwardList()
{
	Element<T>* Temp = Head;
	while (Temp)
	{
		Temp = Temp->pNext;
		pop_front();
	}

}
//Adding elements:
template <typename T>void ForwardList<T>::push_front(T Data)
{
	Element<T>* New = new Element<T>(Data);
	New->pNext = Head;
	Head = New;
	size++;
};
template <typename T>void ForwardList<T>::push_back(T Data)
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
template <typename T>void ForwardList<T>::insert(int Index, T Data)
{
	if (Index > Element<T>::count)
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
template <typename T>void ForwardList<T>::pop_front()
{
	//1)Запоминаем адрес удаляемого элемента
	Element<T>* erase_element = Head;
	//2)Исключаем элемент из списка
	Head = Head->pNext; //исключает элемент из списка
	//3) Удаляем элемент из памяти
	delete erase_element;
	size--;
}
template <typename T>void ForwardList<T>::pop_back()
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
template <typename T>void ForwardList<T>::erase(int index)
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
template <typename T>ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other)
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
}
template <typename T>ForwardList<T>& ForwardList<T>::operator=(ForwardList<T>&& other)noexcept
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
template <typename T>T& ForwardList<T>::operator[](int index)
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
template <typename T>void ForwardList<T>::print()const
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
	cout << "Общее кол-во элементов: " << Element<T>::count << endl;
}
//Operators overload
template <typename T>ForwardList<T>& operator+(const ForwardList<T>& left, const ForwardList<T>& right)
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
