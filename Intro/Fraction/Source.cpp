#include "Fraction.h"
void main()
{
	setlocale(LC_ALL, "ru");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	cout << A << endl;
	double b = 5;
	Fraction B = 5;
	B.print();
	cout << B << endl;
	Fraction C(1, 2);
	C.print();
	cout << C << endl;
	Fraction D(3, 4, 5);
	D.print();
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef arithmetical_operators
	Fraction A(11, 4);
	<<<<<< < HEAD
		Fraction B(5, 6, 7);
	cout << DELIMITER << endl;
	Fraction C = A * B;
	cout << C << endl;
	cout << DELIMITER << endl;
	C = A - B;
	cout << C << endl;
	cout << DELIMITER << endl;
	cout << A / B << endl;
#endif // arithmetical_operators
#ifdef COMPAUND_ASSIGNMENTS
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << A << endl;
	cout << B << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
	cout << A - A << endl;
}
#endif // COMPAUND_ASSIGNMENTS
#ifdef INCREMENT_CHECK
for (double i = .3; i < 10; i++)
{
	cout << i << tab;

}
cout << endl;
for (Fraction i(3, 4); i < 10; i++)
{
	cout << i << tab;

}
cout << endl;
#endif // INCREMENT_CHECK
#ifdef COMPARISON_OPERATORS
Fraction A(1, 2);
Fraction B(5, 10);
cout << A << endl;
cout << B << endl;
/*cout << (A == B) << endl;
if (A==B)
{
	cout << "Дроби равны" << endl;
}
else
{
	cout<< "Дроби разные" << endl;
}*/
cout << (A == B) << endl;
cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
cout << DELIMITER << endl;
cout << A << endl;
cout << B << endl;
#endif // COMPARISON_OPERATORS
#ifdef TYPE_CONVERSION
	//int a = 43;
	////явное преобразование типов - explicit conversion
	//cout << (char)a << endl; //C-like style
	//cout << char(a) << endl; //Function style
	////неявное преобразование - implicit conversion
	//double b = 3.5;
	//cout<<typeid(a + b).name(); 
	Fraction A (5); //explicit constructor можно вызвать только так и невозможно вызвать оператором "="
	cout << A << endl;
	A = (Fraction)8;
	cout << A << endl;
	Fraction B (3, 4, 5);
	double b = B;
	cout <<b<< endl;
	Fraction C = 2.55;
	cout << C << endl;
#endif // TYPE_CONVERSION

	


}

