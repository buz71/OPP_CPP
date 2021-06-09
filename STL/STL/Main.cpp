#include<iostream>
#include<array>
#include<vector>
using namespace std;
using std::cin;
using std::cout;
using std::endl;



#define tab "\t"
#define DELIMITER "-------------------------------------------------------"

//#define STL_ARRAY
#define STL_VECTOR
//#define STL_VECTOR_INSERT
#define HOMEWORK

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


#ifdef HOMEWORK
	int index;
	cout << "¬ведите индекс дл€ удалени€:  "; cin >> index;
	vec.erase(vec.begin()+index);
	print_vector(vec);
	vector_properties(vec);
	reverse_print_vector(vec);
#endif // HOMEWORK

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
	for (vector<T>::iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << tab;
	}
};