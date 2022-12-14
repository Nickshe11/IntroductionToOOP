#include<iostream>
using namespace std;
#define delimiter "________________________________________"
using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);

class String
	
{
	size_t size; //размер строки в байтах
	char* str; //указатель на строку в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	size_t get_size()const
	{
		return size;
	}
	/*void set_size(int size)
	{
		this->size = size;
	}
	void set_str(int i, const char lit)
	{
		this->str[i] = lit;
	}*/

	// Constructors
	explicit String(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	/*String(size_t size)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}*/
	String(const char str[])
	{
		this->size = strlen(str) + 1; // +1 на терминирующий ноль
		this->str = new char [size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)
	{
		//Shallow copy:
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator= (String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		cout << "MoveAssignment:" << this << endl;
		other.size = 0;
		other.str = nullptr;
		return *this;
	}
	String operator+=(String& other)
	{
		return *this = *this + other;
	}
	

	//Methods
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
	char operator[](int i)const		//i - index
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
};

String operator+(const String& left, const String& right)
{
	/*String temp (left.get_size() + right.get_size());
	int i = 0;
	for (; i < left.get_size()-1; i++)
	{
		temp.set_str(i, left.get_str()[i]);
	}
	temp.set_str(i, ' ');
	i++;

	for (int j = 0; i < left.get_size()+ right.get_size(); i++,j++)
	{

		temp.set_str(i, right.get_str()[j]);

	}
	return temp;*/
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}



ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK;
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1; // пустая строка размером 80 Байт
	str1.print();
	cout << str1 << endl;

	String str2(22);// Скобки вместо оператора присваивания из-за того, что конструктор сделали explicit
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4 = str3;//CopyConstructor
	cout << str4 << endl;

	String str5; //DefaultConstructor
	str4 = str5; // CopyAssignment
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str4;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;
	str4 = str2+str1;
	cout << delimiter << endl;
	cout << str4 << endl;
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK
}