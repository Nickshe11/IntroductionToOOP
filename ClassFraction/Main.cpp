#include<iostream>
using namespace std;

#define delimiter "\n_______________________________"

class Fraction;//Объявление класса
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_ineger(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}

	Fraction(double decimal)
	{
		integer = decimal;
		decimal += 1e-10; //округляем результат - скидываем девятки на 10 знаков после запятой в нули
		denominator = 1e+9; //миллиард, то есть 10 в 9 степени
		numerator = (decimal - integer) * denominator;
		reduce();
		cout << "1ArgConstructor double:\t" << this << endl;
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator +=(Fraction second)
	{
		Fraction first = *this;
		first.to_improper();
		second.to_improper();
		this->numerator = first.get_numerator() * second.get_denominator() + second.get_numerator() * first.get_denominator();
		this->denominator = first.get_denominator() * second.get_denominator();
		this->to_proper();
		return *this;
	}

	Fraction& operator -=(Fraction second)
	{
		Fraction first = *this;
		first.to_improper();
		second.to_improper();
		this->numerator = first.get_numerator() * second.get_denominator() - second.get_numerator() * first.get_denominator();
		this->denominator = first.get_denominator() * second.get_denominator();
		this->to_proper();
		return *this;
	}

	Fraction& operator *=(const Fraction& second)
	{
		/*Fraction first = *this;
		first.to_improper();
		second.to_improper();
		this->numerator = first.get_numerator() * second.get_numerator();
		this->denominator = first.get_denominator() * second.get_denominator();
		this->to_proper();
		return *this;*/

		return *this = *this * second;

	}
	Fraction& operator /=(Fraction second)
	{
		Fraction first = *this;
		first.to_improper();
		second.to_improper();
		this->numerator = first.get_numerator() * second.get_denominator();
		this->denominator = first.get_denominator() * second.get_numerator();
		this->to_proper();
		return *this;
	}


	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//Type-cast operators (операторы преобразования типов)

	operator int()const
	{
		//return this->integer;
		return integer + numerator / denominator;
	}
	operator double()const
	{
		//return double(this->integer) + double(this->numerator) / this->denominator;
		return integer + (double)numerator / denominator;
	}

	//Methods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		/*for (int i = 10; i != 1; i--)
		{
			if ((this->numerator) % i == 0 && (this->denominator) % i == 0)
			{
				this->numerator /= i;
				this->denominator /= i;
				i++;
			}
		}
		return *this;*/
		if (numerator == 0)return *this;
		int more, less, rest;//rest - остаток
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;// GCD - greatest common divider (наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	ostream& operator>> (ostream& os)
	{
		int num, denom;
		char d;
		cin >> num;
		cin >> d;
		cin >> denom;
		if (denom == 0) return os;
		this->numerator = num;
		this->denominator = denom;
		return os;
	}

};
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(left.get_numerator() * right.get_numerator(),
	left.get_denominator() * right.get_denominator()
	);
		return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();*/
	/*return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
	//return first.get_integer() == second.get_integer() && first.get_numerator() * second.get_denominator() == second.get_numerator() * first.get_denominator();
}

bool operator !=(const Fraction& first, const Fraction& second)
{
	return !(first == second);
}

bool operator<(Fraction left, Fraction right)
{
	/*if (first.get_integer() == second.get_integer())
		return (first.get_numerator() * second.get_denominator()) < (second.get_numerator() * first.get_denominator());
	else return first.get_integer() < second.get_integer();*/
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}


bool operator>(Fraction left, Fraction right)
{
	/*if (first.get_integer() == second.get_integer())
		return (first.get_numerator() * second.get_denominator()) > (second.get_numerator() * first.get_denominator());
	else return first.get_integer() > second.get_integer();*/
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	/*if (first.get_integer() == second.get_integer())
		return (first.get_numerator() * second.get_denominator()) >= (second.get_numerator() * first.get_denominator());
	else return first.get_integer() >= second.get_integer();*/
	return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	/*if (first.get_integer() == second.get_integer())
		return (first.get_numerator() * second.get_denominator()) <= (second.get_numerator() * first.get_denominator());
	else return first.get_integer() <= second.get_integer();*/
	return !(left > right);
}




//#define CONSTRUCTORS_CHECK

//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define CONVERCION_FROM_OTHER_TO_CLASS
#define HOME_WORK_1
#define HOME_WORK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //DefaultConstructor;
	cout << A << endl;
	double b = 5;
	Fraction B = 5;//Single-Argument Constructor
	cout << B << endl;
	Fraction C(2, 3);
	cout << C << endl;
	Fraction D(2, 3, 4);
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

#if ARITHMETICAL_OPERATORS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	cout << C << endl;
	cout << A / B << endl;
	cout << A + B << endl;

	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	A += B;
	cout << A << endl;
	cout << delimiter << endl;
	A -= B;
	cout << A << endl;
	cout << delimiter << endl;
	A *= B;
	cout << A << endl;
	cout << delimiter << endl;
	A /= B;
	cout << A << endl;
	cout << delimiter << endl;

	Fraction X(2, 25, 100);
	cout << X << endl;
	X.reduce();
	cout << X << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef COMPOUND_ASSIGNMENTS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	A *= B;
	cout << A << endl;
#endif // COMPOUND_ASSIGNMENTS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	/*Fraction A(1, 2);
Fraction B(5, 11);
if (A == B)
{
	cout << "Дроби равны" << endl;
}
else
{
	cout << "Дроби разные" << endl;
}*/
	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef CONVERCION_FROM_OTHER_TO_CLASS
	Fraction A = Fraction(5);
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B;//Default constructor
	cout << delimiter << endl;
	B = (Fraction)8;
	cout << B << endl;
#endif // CONVERCION_FROM_OTHER_TO_CLASS

#ifdef HOME_WORK_1
	Fraction A(2, 3, 4);
	int a = A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
	Fraction B = 2.75;
	cout << B << endl;

#endif // HOME

	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;

}
