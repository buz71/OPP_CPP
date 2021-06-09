#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

class Tree
{
private:
	class Element
	{
	private:
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight) 
		{
			//cout << "ECtor:\t" << this << endl;
		}
		~Element()
		{
			//cout << "EDector:\t" << this << endl;
		}
		bool Is_leaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
		
	}*Root;//Указатель типа Element на корневой элемент
public:
	Element* GetRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TCtor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il):Tree()
	{
		for (int const* it = il.begin(); it!=il.end(); it++)
		{
			Insert(*it);
		}
	}
	Tree(const Tree& other):Tree()
	{
		Copy(other.Root);
		cout << "CopyCtor:\t" << this << endl;
	}
	~Tree()
	{
		Clear(Root);
		cout << "TDector:" << this << endl;
	}
	Tree& operator=(const Tree& other)
	{
		if (this==&other)
		{
			return *this;
		}
		Clear();
		Copy(other.Root);
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Element* begin()const
	{
		return Root;
	}
	Element* end()const
	{
		return nullptr;
	}
//Методы-обертки
	void Copy(Element* Root)
	{
		if (Root==nullptr)
		{
			return;
		}
		Insert(Root->Data);
		Copy(Root->pLeft);
		Copy(Root->pRight);
	}
	void Insert(int Data) 
	{
		Insert(Data, this->Root);
	};
	void Erase(int Data)
	{
		Erase(Data, Root);
	}
	void Print()
	{
		Print(Root);
		cout << endl;
	}
	int MaxValue()
	{
		return MaxValue(Root);
	}
	int MinValue()
	{
		return MinValue(Root);
	}
	int Size()
	{
		return Size(Root);
	}
	int Sum()
	{
		return Sum(Root);
	}
	double AVG()
	{
		return AVG(Root);
	}
	void Clear()
	{
		Clear(Root);
	}
//Methods
	void Insert(const int &Data, Element* Root) // Здесь Element* Root - указатель на ветку (поддерево)
	{
		if (this->Root == nullptr)
		{
			this->Root = new Element(Data);
		}
		if (Root == nullptr) 
		{ 
			return;
		}
		if (Data<Root->Data)
		{
			if (Root->pLeft==nullptr) // если текущий элемент Root не имеет левого потомка
			{
				Root->pLeft = new Element(Data); // создаем его
			}
			else //в противном случае идем дальше
			{
				Insert(Data, Root->pLeft);
			}
		}
		else
		{
			//Упрощенный вариант записи
			/*if (Root->pRight)
			{
				Insert(Data, Root->pRight);
			}
			else
			{
				Root->pRight = new Element(Data);
			}*/

			if (Root->pRight==nullptr)
			{
				Root->pRight = new Element(Data);
			}
			else
			{
				Insert(Data, Root->pRight);
			}
		}
	}
	void Erase(const int &Data, Element*& Root)
	{
		if (Root == nullptr)return;
		if (Data==Root->Data)
		{
			if (Root->Is_leaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = MaxValue(Root->pLeft);
					Erase(MaxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = MinValue(Root->pRight);
					Erase(MinValue(Root->pRight), Root->pRight);
				}
			}
		}
		if (Root)
		{
			Erase(Data, Root->pLeft);
		}
		if (Root)
		{
			Erase(Data, Root->pRight);
		}

	}
	void Print(Element* Root)
	{
		if (Root == nullptr)
		{
			return;
		}
		Print(Root->pLeft);
		cout << Root->Data << tab; //в зависимости от положения cout будет разный вывод
		Print(Root->pRight);
	}
	void Clear(Element*& Root)
	{
		if (Root==nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
		Root = nullptr;
	}
	int MinValue(Element* Root)
	{
		if (Root->pLeft==nullptr)
		{
			return Root->Data;
		}

		MinValue(Root->pLeft);
		//Второй вариант
		//return Root->pLeft == nullptr ? Root->Data : MinValue(Root->pLeft);

	}
	int MaxValue(Element* Root)
	{
		if (Root->pRight == nullptr)
		{
			return Root->Data;
		}
		MaxValue(Root->pRight);
	}   
	int Size(Element* Root)
	{
		if (Root==nullptr)
		{
			return 0;
		}
		else
		{
			return Size(Root->pLeft) + Size(Root->pRight) + 1;
		}
		//Второй вариант
		//return Root == nullptr ? 0 : Size(Root->pLeft) + Size(Root->pRight) + 1;
	}
	int Sum(Element* Root)
	{

		return Root ? Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data : 0;
	}
	double AVG(Element* Root)
	{
		return (double)Sum(Root) / Size(Root);
	}
	int Search(int Target, Element* Root)
	{
		if (Target == Root->Data)
		{
			return Root->Data;
		}
		if (Target<Root->Data)
		{
			if (Root->pLeft==nullptr)
			{
				return Root->Data;
			}

			Search(Target, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)
			{
				return Root->Data;
			}
			Search(Target, Root->pRight);
		}

	}
	void Erase(Element* Root, int Index)
	{
		if (Root->pLeft==nullptr&&Root->pRight==nullptr)
		{
			return;
		}

		if (Index<Root->Data)
		{
			Erase(Root->pLeft, Index);

			if (Root->Data==Index)
			{

			}
		}
		else
		{
			Erase(Root->pRight, Index);
		}
		
	}
};

void main()
{
	setlocale(LC_ALL, "RU");
	int n; //размер дерева
	cout << "Количество элементов дерева:"; cin >> n;
	Tree tree = {25,16,32,11,18,36,64,55,80,54,58,77,85};
	Tree tree2 = tree;
	tree.Print();
	tree2.Print();
	//int value; //размер дерева
	//cout << "Введите удаляемое значение:"; cin >> value;
	//tree.Erase(value);
	//tree.Print();
	//tree.Clear();
	//tree.Print();
	//tree2.Print();
}