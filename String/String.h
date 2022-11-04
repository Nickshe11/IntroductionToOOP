#pragma once
#include<iostream>
using namespace std;

/// /////////////////////////////////////
/// Class declaration (ќбъ€вление класса)
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String

{
	size_t size; //размер строки в байтах
	char* str; //указатель на строку в динамической пам€ти
public:
	const char* get_str()const;
	char* get_str();
	size_t get_size()const;

	// Constructors
	explicit String(size_t size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//Operators
	String& operator=(const String& other);
	String& operator= (String&& other);
	String operator+=(String& other);

	char operator[](int i)const;
	char& operator[](int i);

	//Methods
	void print()const;
};

/// Class declaration END ( онец объ€влени€ класса)
/// /////////////////////////////////////