#include "String.h"
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define OPERATOR_PLUS_CHECK
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();
	String str2 = "Hello";
	str2.print();
	cout << str2 <<endl;
	cout << "Str2:\t" << str2 << endl;
	String str3 = str2;
	cout << "Str3:\t" << str3 << endl;
	String str4;
	str4 = str3;
	cout << "Str4:\t" << str4 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK

	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif //  ASSIGNMENT_CHECK
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << DELIMITER << endl;
	String str3 = str1 + str2; //Оператор + будет выполнять конкатенацию (слияние) строк
	cout << DELIMITER << endl;
	cout << str3 << endl;
#endif // OPERATOR_PLUS_CHECK
	
	

			

}