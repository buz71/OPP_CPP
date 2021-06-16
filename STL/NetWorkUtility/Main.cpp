#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
#define WAL //wake on lan

void main()
{
	setlocale(LC_ALL, "RU");
#ifdef WAL
	string source_file_name; 
	string destination_file_name;
	string ext = ".txt";
	cout << "¬ведите им€ исходного файла: "; getline(cin,source_file_name); //вводить нужно с расширением
	cout << "¬ведите им€ конечного файла: "; getline(cin, destination_file_name); //вводить нужно с расширением
	if (source_file_name.find(ext)==string::npos)
	{
		source_file_name += ext;
	}
	if (destination_file_name.find(ext) == string::npos)
	{
		destination_file_name += ext;
	}
	ifstream fin(source_file_name);
	string IP;
	string MAC;
	if (fin.is_open())
	{
		ofstream fout(destination_file_name);
		//while (!fin.eof())
		while (fin >> IP >> MAC)
		{
			//fin >> IP >> MAC;
			cout << MAC << tab << IP << endl;
			fout << MAC << tab << IP << endl;
		}
	}
	else
	{
		cerr << "File not found";
	}
	fin.close();
	//fout.close();
	string cmd = "notepad "+destination_file_name;
	system(cmd.c_str());
#endif // WAL

	

						
}