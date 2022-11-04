#include"String.h"

/// /////////////////////////////////////
/// Class definition (ќпределение класса)



const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
std::size_t String::get_size()const
{
	return size;
}

// Constructors
String::String(size_t size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {}; если пам€ть выделили в заголовке, в теле мы ее не выдел€ем
	cout << "DefConstructor:\t" << this << endl;
}
/*String(size_t size)
{
	this->size = size;
	this->str = new char[size] {};
	cout << "Constructor:\t" << this << endl;
}*/
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1; // +1 на терминирующий ноль
	//this->str = new char [size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << endl;
}
String::String(const String& other) : String(other.str)
{
	//Deep copy - побитовое копирование
	/*this->size = other.size;
	this->str = new char[size] {};*/
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//Shallow copy:
	/*this->size = other.size;
	this->str = other.str;*/
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[]this->str;
	cout << "Destructor:\t" << this << endl;
}

//Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[]this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator= (String&& other)
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
String String::operator+=(String& other)
{
	return *this = *this + other;
}


//Methods
void String::print()const
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}
char String::operator[](int i)const		//i - index
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

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

/// CLASS DEDEFINITION END ( онец определени€ класса)
/// /////////////////////////////////////