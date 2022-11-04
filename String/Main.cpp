#include<iostream>
using namespace std;
#define delimiter "________________________________________"
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

#include"String.h"


//#define CONSTRUCTORS_CHECK;
#define OPERATOR_PLUS_CHECK
//#define WAYS_TO_CALL_CONSTRUCTORS

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
	String str5 = str1;
	cout << str5 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef WAYS_TO_CALL_CONSTRUCTORS
	String str1;			//DefaultConstructor
	String str2(5);			//SingleArgument type 'int'
	String str3 = "Hello";	//SingleArgument type 'const char'
	String str4();			//Это выражение НЕ создает объект, а просто объявляет функцию str4, которая ничего не принимает и возвращает значение типа 'String'
							//компилятор эту строку пропускает
	//str4.print();
	// Если нужно явно вызвать конструктор по умлолчанию, то это можно сделать так:
	String str5{};			// Явный вызов конструктора по умолчанию
	str5.print();
	String str6{ 7 };
	str6.print();
	String str7{ "Hello" };
	str7.print();
#endif // WAYS_TO_CALL_CONSTRUCTORS


}