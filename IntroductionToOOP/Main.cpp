#include <iostream>
using namespace std;
#define tab '\t'

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:
	Point()
	{
		x = y = double();
		//double() - значение по умолчанию для типа данных double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	/*double distance()
	{
		double c = sqrt((this->x * this->x) + (this->y * this->y));
		return c;
	}*/
};

//#define STRUCT_POINT
//#define GET_SET_CHECK

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP" << endl; 

#ifdef STRUCT_POINT
	int a; // объявление переменной 'a' типа int
	Point A; // объявление переменной 'A' типа Point
			// Объявление объекта 'A' структуры 'Point'
			// Объявление экземпляра 'A' структуры 'Point'
	A.x = 2.2;
	A.y = 3.4;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif // STRUCT_POINT

#ifdef GET_SET_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();
	/*cout << A.distance() << endl;*/

	Point B;
	B.set_x(5);
	B.set_y(6);
	B.print();
	/*double Two_Points()
	{
		double A_x = A.get_x;
		double A_y = A.get_y;
		double B_x = B.get_x;
		double B_y = B.get_y;
		if (A_x>=B_x)
	}*/
#endif // GET_SET_CHECK

	Point A; //Default constructor
	A.print();

	Point B = 5; // Single-Argument constructor
	B.print();
	
	Point C (2,3);
	C.print();
}