#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <direct.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"
//#define WAL //wake on lan

void main()
{
	setlocale(LC_ALL, "RU");
#ifdef WAL
	string source_file_name; 
	string destination_file_name;
	string ext = ".txt";
	fout << "¬ведите им€ исходного файла: "; getline(cin,source_file_name); //вводить нужно с расширением
	fout << "¬ведите им€ конечного файла: "; getline(cin, destination_file_name); //вводить нужно с расширением
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
			fout << MAC << tab << IP << endl;
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
	string room_number;
	cout << "¬ведите номер аудитории: "; cin >> room_number;
	string directory = "Files";
	_chdir(directory.c_str());
	string source_file_name = room_number+" RAW.txt";
	string dhcp_file_name = room_number + ".dhcpd";
	string wal_file_name = room_number + ".wal";
	string mac, ip;
	ifstream fin(source_file_name);
	if (fin.is_open())
	{
		ofstream dhcp_fout(dhcp_file_name);
		ofstream wal_fout(wal_file_name);
		for (int i = 1; fin>>ip>>mac; i++)
		{
			wal_fout << mac << tab << ip <<endl;
			std::replace(mac.begin(),mac.end(),'-',':');
			cout << "host 201-" << i << endl;
			cout << "{";
			cout << "\thardware ethernet\t" << mac << ";\n";
			cout << "\tfixed-adress\t\t" << ip << ";\n";
			cout << "}";
			cout << endl;
			
			dhcp_fout << "host 201-" << i << endl;
			dhcp_fout << "{";
			dhcp_fout << "\thardware ethernet\t" << mac << ";\n";
			dhcp_fout << "\tfixed-adress\t\t" << ip << ";\n";
			dhcp_fout << "}";
			dhcp_fout << endl;
		}
		//string cmd = "notepad " + dhcp_file_name;
		string cmd = "start notepad ";
		system((cmd + wal_file_name).c_str());
		system((cmd + dhcp_file_name).c_str());
	}
	else
	{
		cout << "File not found"<<endl;
	}
	fin.close();


	

						
}