#include<iostream>
#include<array>
#include<vector>
#include <list>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define DELIMITER "-------------------------------------------------------"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_VECTOR_INSERT
//#define STL_VECTOR_ERASE
template<typename T>void vector_properties(const vector<T>& vec);
template<typename T>void print_vector(const vector<T>& vec);
template<typename T>void reverse_print_vector(const vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << tab;
		cout << arr.at(i) << tab;
	}
	cout << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *arr.data() << endl;

	arr.fill(123);
	for (int i : arr)
		cout << i << tab;
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива
	vector<int> vec = { 0,1,2,3,5,8,13,21,34 };
	vec.push_back(55);
	/*cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;*/
	//vector_properties(vec);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	vec.reserve(45);
	vec.shrink_to_fit();
	vector_properties(vec);
	for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
	{
		cout << *it << tab;
	}
	cout << endl;
#ifdef STL_VECTOR_INSERT
	int index;
	int count;
	int value;
	cout << "¬ведите индекс: "; cin >> index;
	cout << "¬ведите значение: "; cin >> value;
	cout << "¬ведите количество добавл€емых элементов: "; cin >> count;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, value, count);
	for (int i : vec)
	{
		cout << i << tab;
	}
	vector_properties(vec);
	cout << DELIMITER << endl;
	vec.insert(vec.begin() + 5, { 1024,2048,3072,4096 });
	print_vector(vec);
	cout << endl;
	cout << DELIMITER << endl;
#endif // STL_VECTOR_INSERT
#endif // STL_VECTOR

	vector<int> vec = { 3,5,8,13,21,34,55 };
	print_vector(vec);
	/*int index;
	cout << "¬ведите индекс удалени€"; cin >> index;
	vector <int>::iterator position = vec.begin()+index;
	vec.erase(position);
	print_vector(vec);*/
#ifdef STL_VECTOR_ERASE
	int index_start, index_end;
	cout << "¬ведите начало удал€емого диапазона: "; cin >> index_start;
	cout << "¬ведите конец удал€емого диапазона: "; cin >> index_end;
	vec.erase(vec.begin() + index_start, vec.begin() + index_end);
	print_vector(vec);
	vector_properties(vec);
#endif // STL_VECTOR_ERASE
	reverse_print_vector(vec);

}

template<typename T>void vector_properties(const vector<T>& vec)
{
	cout << "Size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;
}
template<typename T>void print_vector(const vector<T>& vec) 
{
	for (int i : vec)
	{
		cout << i << tab;
	}
	cout << endl;
};
template<typename T>void reverse_print_vector(const vector<T>& vec)
{
	for (vector<int>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); it++)
	{
		cout << *it << tab;
	}
};