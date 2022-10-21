#include <iostream>
using namespace std;
#define tab '\t'
#define delimiter "________________________________"

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
	/*Point()
	{
		x = y = double();
		//double() - значение по умолчанию для типа данных double
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	// Methods:
	 double distance(const Point& other) const
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B);

//#define STRUCT_POINT
//#define GET_SET_CHECK
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK

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


	Point B;
	B.set_x(5);
	B.set_y(6);
	B.print();

#endif // GET_SET_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'В' = " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'В' = " << B.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A' = " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'В' = " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'В' = " << distance(B, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A' = " << distance(B, A) << endl;

#endif // DISTANCE_CHECK


#ifdef CONSTRUCTORS_CHECK
	Point A; //Default constructor
	A.print();

	Point B = 5; // Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;  //CopyConstructor
	D.print();
	Point E; //DefaultConstructor
	E = D; //Assignment operator (CopyAssignment)
	E.print();
#endif // CONSTRUCTORS_CHECK

	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
}

double distance(const Point& A, const Point& B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}