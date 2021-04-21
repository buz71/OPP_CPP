#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Box
{
private:
	double width;
	double height;
	double lenght;
	string material;
public:
	double get_width()const
	{
		return this->width;
	}
	double get_height()const
	{
		return this->height;
	}
	double get_lenght()const
	{
		return this->lenght;
	}
	const string& get_material()const
	{
		return this->material;
	}
	//constructors
	Box(double width, double height, double lenght, const string& material):
	width(width), height(height),lenght(lenght),material(material)
	{
		cout << "BoxCtor:\t\t" << this << endl;
	}
	~Box()
	{
		cout << "BoxDestructor:\t\t" << this << endl;
	}
	//methods
	void info()const
	{
		cout << "Dimensions:" << width << " x " << height << " x " << lenght << endl;
		cout << "Материал: " << material << endl;
	}
};

class GiftBox:public Box
{
private:
	string cover;
public:
	const string& get_cover()const
	{
		return cover;
	}
	GiftBox(double width, double height, double lengh, const string& materail, const string& cover) :
		Box(width, height, lengh, materail)
	{
		this->cover = cover;
		cout << "GiftBoxCtor:\t" << this <<endl;
	}
	~GiftBox()
	{
		cout << "GiftBoxDestructor:\t" << this << endl;
	}
	//methods
	void info()const
	{
		Box::info();
		cout << "Обложка\t" << cover << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "RU");
	/*Box box(2, 5, 8, "Картон");
	box.info();*/
	GiftBox giftbox(2,5,8,"Картон", "с котами и мышами");
	giftbox.info();


}