#include <iostream>
using namespace std;
#define tab '\t'

class Point
{
	double x;
	double y;
public:
};

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl; 

	int a; // объявление переменной 'a' типа int
	Point A; // объявление переменной 'A' типа Point
			// Объявление объекта 'A' структуры 'Point'
			// Объявление экземпляра 'A' структуры 'Point'
	A.x = 2.2;
	A.y = 3.4;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
}