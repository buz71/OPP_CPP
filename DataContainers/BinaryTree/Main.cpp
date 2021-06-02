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
		friend class Tree;
		
	}*Root;//Указатель типа Element на корневой элемент
public:
	Element* GetRoot()
	{
		return Root;
	}
	Tree():Root(nullptr)
	{
		cout << "TCtor:\t" << this << endl;
	}
	~Tree()
	{
		Clear(Root);
		cout << "TDector:" << this << endl;
	}
//Methods
	void Insert(int Data, Element* Root) // Здесь Element* Root - указатель на ветку (поддерево)
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
	void Clear(Element* Root)
	{
		if (Root==nullptr)return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
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
		return (double)Sum(Root) / (double)Size(Root);
	}
};

void main()
{
	setlocale(LC_ALL, "RU");
	int n; //размер дерева
	cout << "Количество элементов дерева:"; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.Insert(rand() % 100+10,tree.GetRoot());
	}
	tree.Print(tree.GetRoot());
	cout << endl;
	cout <<"MinValue: "<< tree.MinValue(tree.GetRoot()) << endl;
	cout << "MaxValue: " << tree.MaxValue(tree.GetRoot()) << endl;
	cout << "Sum: " << tree.Sum(tree.GetRoot()) << endl;
	cout << "AVG: " << tree.AVG(tree.GetRoot()) << endl;
}