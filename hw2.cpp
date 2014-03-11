/*****************************************************************************************
Edward Chen
703909636
hw2.cpp
The purpose of this assignment is to create a rational class that displays two polynomials in the form p(x)/q(x) 
and prints a sum, subtraction, division and multiplication of the two inputs
January 17, 2013
******************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Polynomial class stores polynomials in the form of vectors
class Polynomial
{
	public:
	// Constructors
		Polynomial ();
		Polynomial (vector <int> coeffs);
	
	// Accessors
		int Degree() const;
		int Coefficient (int k) const;
		void print() const;
	
	// Mutator
		void constantMultiply (int x);
		void Transform();
		void evaluateAt (double x);
	
	//operator member functions
		Polynomial operator++(int);
		Polynomial& operator++();
		Polynomial operator--();
		Polynomial& operator+=(Polynomial& poly1);
		Polynomial& operator-=(Polynomial& poly1);
		Polynomial& operator*=(Polynomial& poly1);

	private:
		vector <int> coefficient;
};

// Non member operator functions
Polynomial operator+ (Polynomial poly1, Polynomial poly2);
Polynomial operator- (Polynomial poly1, Polynomial poly2);
Polynomial operator* (Polynomial poly1, Polynomial poly2);

// boolean operators
bool operator== (Polynomial poly1, Polynomial poly2);
bool operator!= (Polynomial poly1, Polynomial poly2);
bool operator<= (Polynomial poly1, Polynomial poly2);
bool operator>= (Polynomial poly1, Polynomial poly2);
bool operator> (Polynomial poly1, Polynomial poly2);
bool operator< (Polynomial poly1, Polynomial poly2);

// Rational class stores polynomials in the form num/denom
class Rational:public Polynomial 
{
public: 
// Constructors
	Rational ();
	Rational (Polynomial p);
	Rational (Polynomial pN, Polynomial pD);
	void evaluateAt (double x);
	void display();

//operator member functions
	Rational operator++(int);
	Rational& operator++();
	Rational operator--();
	Rational& operator+=(Rational& rat1);
	Rational& operator-=(Rational& rat1);
	Rational& operator*=(Rational& rat1);
	Rational& operator/=(Rational& rat1);

private:
	Polynomial num;
	Polynomial denom;
};



// Non-member operators
Rational operator+ (Rational rat1, Rational rat2);
Rational operator- (Rational rat1, Rational rat2);
Rational operator* (Rational rat1, Rational rat2);
Rational operator/ (Rational rat1, Rational rat2);

int main()
{
	int entry;
	vector <int> new_poly1;
	vector <int> new_poly2;
	vector <int> new_poly3;
	Polynomial poly1;
	Polynomial poly2;
	Polynomial poly3;
	Polynomial poly4;
	Rational rat1 (poly1, poly2);
	Rational rat2 (poly1);
	Rational rat3 (poly2);
	

	//Hard code of vector (1+x^2-3x^4)
	new_poly3.push_back(1);
	new_poly3.push_back(0);
	new_poly3.push_back(1);
	new_poly3.push_back(0);
	new_poly3.push_back(-3);
	poly4 = new_poly3;
	Rational new_rat(poly4);

	cout << "Hello! Please input the coefficients of the first polynomial"<<endl; 
	cout << "When you are finished, enter -123456789"<<endl;	
	cin >> entry;
	while (entry != -123456789)
	{
		new_poly1.push_back(entry);
		cin >> entry;
	}
	poly1 = new_poly1;
	cout << "Your first polynomial is p(x) = ";
	poly1.print();
	cout << endl;
	cout << "Please input the coefficients of the second polynomial" << endl;
	cin >> entry;
	while (entry != -123456789)
	{
		new_poly2.push_back(entry);
		cin >> entry;
	}
	poly2 = new_poly2;
	cout << "Your second polynomial is q(x) = ";
	poly2.print();
	cout << endl;
	cout << "p(x) + q(x) = ";
	poly3 = poly1 + poly2;
	poly3.print();
	cout << endl;
	cout << "p(x) - q(x) = ";
	poly3 = poly1 - poly2;
	poly3.print();
	cout << endl;
	cout << "p(x) * q(x) = ";
	poly3 = poly1 * poly2;
	poly3.print();
	cout << endl;
	cout << "p(x) / q(x) = ";
	rat1.display();
	cout << "p(x)/q(x)+p(x)*q(x) = ";
	rat1 = rat1 + (rat2 * rat3);
	rat1.display();
	cout << "p(x) + 1 = ";
	poly1++;
	poly1.print();
	cout << "p(x) + 2 = ";
	poly1++;
	poly1.print();
	cout << "(p(x)/q(x)) * (1+x^2-3x^4) = ";
	Rational temp = rat1 * new_rat;
	temp.display();
	cout << "Does p(x) equal q(x)? " << endl;
	if (poly1 == poly2)
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	cout << "Is p(x) <= q(x)" << endl;
	if (poly1 <= poly2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "Thanks for using my program" << endl;
	

	return 0;
}

/******************************************
This is the default constructor
@no parameters
initializes the polynomial to 0 by default
******************************************/
Polynomial::Polynomial ()
{
	
}
/******************************************
This is the constructor that sets the private variable coefficient to the input parameter coeffs
@ parameter vector <int> coeffs
does not return anything
******************************************/
Polynomial::Polynomial(vector <int> coeffs)
{
	coefficient = coeffs;
}
/******************************************
This function returns the highest degree of the polynomial
@no parameters
returns the integer of the highest degree
******************************************/
int Polynomial::Degree() const
{
	int i = coefficient.size()-1;
	
	return i;
}
/******************************************
This function returns the coefficient of the polynomial at index k
@ parameter integer k
returns integer coefficient
******************************************/
int Polynomial::Coefficient(int k) const
{
	return coefficient [k];
}
/******************************************
// This function prints the polynomial 
@ no parameters
// prints out the polynomial from smallest to largest degree
// Supresses terms with coefficient of 0, 1, -1
// Supresses exponent of 1
// For negative coefficients, prints out -3x instead of +-3x
******************************************/
void Polynomial::print() const
{
	for (int i = 0; i <coefficient.size(); i++)
	{
		if (i == 0 && Coefficient(i) == 0 && coefficient.size() == 1)
		{
			cout << 0;
		}
		else if (i == 0 && Coefficient(i) != 0)
		{
			cout << Coefficient(i);
		}
		else if (i == 1 && Coefficient(i) != 0)
		{
			if (Coefficient(i) > 0)
			{
				cout << "+" << Coefficient(i) << "x";
			}
			else if (Coefficient(i) == 1 || Coefficient(i) == -1)
			{
				if (Coefficient(i) == 1)
				{
					cout << "+" << "x";
				}
				else
				{
					cout << "-"<< "x";
				}
			}
			else
			{
				cout << Coefficient(i) << "x";
			}
		}
		else if (i !=0 && (Coefficient(i) == 1 || Coefficient(i) == -1))
		{
			if (Coefficient(i) == 1)
			{
				cout << "+" << "x^" << i;
			}
			else
			{
				cout << "x^" << i;
			}
		}
		else if (Coefficient(i) == 0)
		{
			continue;
		}
		else 
		{
			if (Coefficient(i) > 0)
			{
				cout << "+" << Coefficient(i) << "x^" << i;
			}
			else
			{
				cout << Coefficient(i) << "x^" << i;
			}
		}
	}
}
/******************************************
This function multiplies the polynomial by an integer constant, x
@ parameter int x
has no return 
******************************************/
void Polynomial::constantMultiply(int x)
{
	vector <int> poly;
	for (int i = 0; i < poly.size(); i++)
	{
		poly[i] = poly[i] * x;
	}
}
/******************************************
This function calculates the derivative of the polynomial
@ no parameters
prints out the derivative
******************************************/
void Polynomial::Transform()
{
	for (int i = 0; i < coefficient.size(); i++)
	{
		coefficient[i] = i * Coefficient(i);
		if (Coefficient(i) == 0)
		{
			continue;
		}
		else 
		{
			cout << coefficient[i] << "x^" << Degree()-1 << "+";
		}
	}
}

/******************************************
This function evaluates the polynomial at the numerical value x
@ parameter double x
has no return 
******************************************/
void Polynomial::evaluateAt(double x)
{
	vector <double> poly;
	double sum = 0;

	for (int i = 0; i < poly.size(); i++)
	{
		sum += coefficient[i] * pow(x,i);
	}
	cout << sum;
}

/******************************************
This operator overloads ++ to add one to index 0 postfix
@ no parameters
Adds one to polynomial
******************************************/
Polynomial Polynomial::operator++(int)
{
	coefficient[0]++;
	return *this;
}

/******************************************
This operator overloads ++ to add one to index 0 prefix
@ no parameters
Adds one to polynomial
******************************************/
Polynomial& Polynomial::operator++()
{
	coefficient[0]++;
	return *this;
}

/******************************************
This operator overloads -- to minus one to index 0
@ no parameters
Minus one to polynomial
******************************************/
Polynomial Polynomial::operator--()
{
	coefficient[0]--;
	return *this;
}

/******************************************
This operator overloads += to perform poly1 = poly1 + poly2
@ no parameters
poly1 = poly1 + poly2
******************************************/
Polynomial& Polynomial::operator+=(Polynomial& poly1)
{
	*this = *this + poly1;

	return *this;
}

/******************************************
This operator overloads -= to perform poly1 = poly1 - poly2
@ no parameters
poly1 = poly1 - poly2
******************************************/
Polynomial& Polynomial::operator-=(Polynomial& poly1)
{
	*this = *this - poly1;

	return *this;
}

/******************************************
This operator overloads *= to perform poly1 = poly1 * poly2
@ no parameters
poly1 = poly1 * poly2
******************************************/
Polynomial& Polynomial::operator*=(Polynomial& poly1)
{
	*this = *this * poly1;

	return *this;
}

/******************************************
This function adds two polynomials
@ parameters poly1
@ parameters poly2
returns the sum of poly1 and poly2
******************************************/
Polynomial operator+(Polynomial poly1, Polynomial poly2)
{
	vector <int> new_poly3;
	Polynomial poly3;
	if (poly1.Degree() == poly2.Degree())
	{
		for (int k = 0; k < poly1.Degree()+1; k++)
		{
			new_poly3.push_back(0);
		}
		for (int i = 0; i < poly1.Degree()+1; i++)
		{
			new_poly3[i] = poly1.Coefficient(i) + poly2.Coefficient(i);
		}
	}
	else if (poly1.Degree() > poly2.Degree())
	{
		for (int k = 0; k < poly2.Degree()+1; k++)
		{
			new_poly3.push_back(0);
		}
		for (int j = 0; j < poly2.Degree()+1; j++)
		{
			new_poly3[j] = poly1.Coefficient(j) + poly2.Coefficient(j);
		}
		for (int x = poly2.Degree() + 1; x < poly1.Degree()+1; x++)
		{
			new_poly3.push_back(poly1.Coefficient(x));
		}
	}
	else
	{
		for (int k = 0; k < poly1.Degree()+1; k++)
		{
			new_poly3.push_back(0);
		}
		for (int j = 0; j < poly1.Degree()+1; j++)
		{
			new_poly3[j] = poly1.Coefficient(j) + poly2.Coefficient(j);
		}
		for (int x = poly1.Degree() + 1; x < poly2.Degree()+1; x++)
		{
			new_poly3.push_back(poly2.Coefficient(x));
		}
	}
	poly3 = new_poly3;
	return poly3;
}

/******************************************
This function subtracts two polynomials
@ parameters poly1
@ parameters poly2
returns poly1 minus poly2
******************************************/
Polynomial operator-(Polynomial poly1, Polynomial poly2)
{
	vector <int> new_poly3;
	Polynomial poly3;
	if (poly1.Degree() == poly2.Degree())
	{
		for (int k = 0; k < poly1.Degree()+1; k++)
		{
			new_poly3.push_back(0);
		}
		for (int i = 0; i < poly1.Degree()+1; i++)
		{
			new_poly3[i] = poly1.Coefficient(i) - poly2.Coefficient(i);
		}
	}
	else if (poly1.Degree() > poly2.Degree())
	{
		for (int k = 0; k < poly2.Degree()+1; k++)
		{
			new_poly3.push_back(0);
		}
		for (int j = 0; j < poly2.Degree()+1; j++)
		{
			new_poly3[j] = poly1.Coefficient(j) - poly2.Coefficient(j);
		}
		for (int x = poly2.Degree() + 1; x < poly1.Degree()+1; x++)
		{
			int y = -1 * poly1.Coefficient(x);
			new_poly3.push_back(y);
		}
	}
	else
	{
		for (int k = 0; k < poly1.Degree()+1; k++)
		{
			new_poly3.push_back(0);
		}
		for (int j = 0; j < poly1.Degree()+1; j++)
		{
			new_poly3[j] = poly1.Coefficient(j) - poly2.Coefficient(j);
		}
		for (int x = poly1.Degree() + 1; x < poly2.Degree()+1; x++)
		{
			int y = -1 * poly2.Coefficient(x);
			new_poly3.push_back(y);
		}
	}
	poly3 = new_poly3;
	return poly3;
}

/******************************************
This function multiplies two polynomials
@ parameters poly1
@ parameters poly2
returns the multiplication of poly1 and poly2
******************************************/
Polynomial operator*(Polynomial poly1, Polynomial poly2)
{
	vector <int> new_poly3;
	Polynomial poly3;
	for (int k = 0; k < poly1.Degree() + poly2.Degree()+1; k++)
	{
		new_poly3.push_back(0);
	}
	for (int i = 0; i < poly1.Degree()+1; i++)
	{
		for (int j = 0; j < poly2.Degree()+1; j++)
		{
			new_poly3[i+j] = new_poly3[i+j] + poly1.Coefficient(i) * poly2.Coefficient(j);
		}
	}
	poly3 = new_poly3;
	return poly3;
}

/******************************************
This function tests the coefficient of two polynomials to see if they're equal
@ parameters poly1
@ parameters poly2
returns true if equal
******************************************/
bool operator== (Polynomial poly1, Polynomial poly2)
{
	bool equal;
	for (int i = 0; i < poly1.Degree()+1; i++)
	{
		if (poly1.Coefficient(i) == poly2.Coefficient(i))
		{
			equal = true;
		}
		else
			equal = false;
	}
	return equal;
}

/******************************************
This function tests the coefficient of two polynomials to see if they're equal
@ parameters poly1
@ parameters poly2
returns false if not equal
******************************************/
bool operator!= (Polynomial poly1, Polynomial poly2)
{
	bool equal;
	for (int i = 0; i < poly1.Degree()+1; i++)
	{
		if (poly1.Coefficient(i) != poly2.Coefficient(i))
		{
			equal = false;
		}
		else
			equal = true;
	}
	return equal;
}

/******************************************
This function tests the degrees of two polynomials to see which is bigger
@ parameters poly1
@ parameters poly2
returns true if poly1 is smaller
******************************************/
bool operator< (Polynomial poly1, Polynomial poly2)
{
	bool equal = true;
	if (poly1.Degree() < poly2.Degree())
		equal = true;
	else
		equal = false;
	return equal;
}

/******************************************
This function tests the degrees of two polynomials to see which is bigger
@ parameters poly1
@ parameters poly2
returns true if poly1 > poly2
******************************************/
bool operator> (Polynomial poly1, Polynomial poly2)
{
	bool equal = true;
	if (poly1.Degree() > poly2.Degree())
		equal = true;
	else
		equal = false;
	return equal;
}

/******************************************
This function tests the degrees of two polynomials to see which is bigger or equal
@ parameters poly1
@ parameters poly2
returns true if poly1 <= poly2
******************************************/
bool operator<= (Polynomial poly1, Polynomial poly2)
{
	bool equal = true;
	if (poly1.Degree() == poly2.Degree() || poly1.Degree() < poly2.Degree())
		equal = true;
	else
		equal = false;
	return equal;
}

/******************************************
This function tests the degrees of two polynomials to see which is bigger or equal
@ parameters poly1
@ parameters poly2
returns true if poly1 >= poly2
******************************************/
bool operator>= (Polynomial poly1, Polynomial poly2)
{
	bool equal = true;
	if (poly1.Degree() == poly2.Degree() || poly1.Degree() > poly2.Degree())
		equal = true;
	else
		equal = false;
	return equal;
}


/******************************************
This is the default constructor
@ no parameters
initializes the rational to 0/1 by default
******************************************/
Rational::Rational()
{
	vector <int> new_num;
	vector <int> new_denom;
	new_num.push_back(0);
	new_denom.push_back(1);
	num = new_num;
	denom = new_denom;
}

/******************************************
This is a constructor with parameters for numerator
@ Polynomial p
initializes the rational to p/1 by default
******************************************/
Rational::Rational(Polynomial p)
{
	vector <int> new_denom;
	new_denom.push_back(1);
	num = p;
	denom = new_denom;
}

/******************************************
This is a constructor with parameters for numerator and denominator
@ Polynomial pN
@ Polynomial pD
initializes the rational to pN/pD by default
******************************************/
Rational::Rational(Polynomial pN, Polynomial pD)
{
	num = pN;
	denom = pD;
}


/******************************************
This function evalutes the Rational at the numerical value x
@ double x
returns sum at the numerical value x
******************************************/
void Rational::evaluateAt(double x)
{
	vector <double> poly;
	double num = 0;
	double denom = 0;

	for (int i = 0; i < poly.size(); i++)
	{
		num += poly[i] * pow(x,i);
	}
	for (int i = 0; i < poly.size(); i++)
	{
		denom += poly[i] * pow(x,i);
	}
	cout << num << "/" << denom;
}


/******************************************
This function prints out the Rational
@ no parameter
prints num/denom
******************************************/
void Rational::display()
{
	num.print();
	cout << "/";
	denom.print();
}

/******************************************
This function adds two Rationals
@ parameters rat1
@ parameters rat2
returns the sum of rat1 and rat2
******************************************/
Rational operator+(Rational rat1, Rational rat2)
{
	Polynomial num1, num2;
	Polynomial denom1, denom2;
	Polynomial num, denom;
	Rational rat(Polynomial num, Polynomial denom);
	
	num = (num1 * denom2) + (num2 + denom1);
	denom = denom1 * denom2;
		
	return rat(num,denom);
}

/******************************************
This function subtracts two Rationals
@ parameters rat1
@ parameters rat2
returns rat1 minus rat2
******************************************/
Rational operator-(Rational rat1, Rational rat2)
{
	Polynomial num1, num2;
	Polynomial denom1, denom2;
	Polynomial num, denom;
	Rational rat(Polynomial num, Polynomial denom);
	
	num = (num1 * denom2) - (num2 + denom1);
	denom = denom1 * denom2;
	
	return rat(num,denom);
}

/******************************************
This function multiplies two Rationals
@ parameters rat1
@ parameters rat2
returns the multiplication of rat1 and rat2
******************************************/
Rational operator*(Rational rat1, Rational rat2)
{
	Polynomial num1, num2;
	Polynomial denom1, denom2;
	Polynomial num, denom;
	Rational rat(Polynomial num, Polynomial denom);
	num = num1 * num2;
	denom = denom1 * denom2;
	
	return rat(num,denom);
}

/******************************************
This function divides two Rationals
@ parameters rat1
@ parameters rat2
returns the division of rat1 and rat2
******************************************/
Rational operator/(Rational rat1, Rational rat2)
{
	Polynomial num1;
	Polynomial num2;
	Polynomial denom1;
	Polynomial denom2;
	Polynomial num;
	Polynomial denom;
	Rational rat(Polynomial num, Polynomial denom);
	num = num1 * denom2;
	denom = denom1 * num2;
	
	return rat(num,denom);
}

/******************************************
This operator overloads ++ to add one to Rational postfix
@ no parameters
Adds one to Rational
******************************************/
Rational Rational::operator++(int)
{
	num + denom;
	return *this;
}

/******************************************
This operator overloads ++ to add one to Rational prefix
@ no parameters
Adds one to Rational
******************************************/
Rational& Rational::operator++()
{
	num + denom;
	return *this;
}

/******************************************
This operator overloads -- to subtract one to Rational 
@ no parameters
Adds one to Rational
******************************************/
Rational Rational::operator--()
{
	num - denom;
	return *this;
}

/******************************************
This operator overloads += to perform rat1 = rat1 + rat2
@ no parameters
rat1 = rat1 + rat2
******************************************/
Rational& Rational::operator+=(Rational& rat1)
{
	*this = *this + rat1;

	return *this;
}

/******************************************
This operator overloads -= to perform rat1 = rat1 - rat2
@ no parameters
rat1 = rat1 - rat2
******************************************/
Rational& Rational::operator-=(Rational& rat1)
{
	*this = *this - rat1;

	return *this;
}

/******************************************
This operator overloads *= to perform rat1 = rat1 * rat2
@ no parameters
rat1 = rat1 * rat2
******************************************/
Rational& Rational::operator*=(Rational& rat1)
{
	*this = *this * rat1;

	return *this;
}

/******************************************
This operator overloads /= to perform rat1 = rat1 / rat2
@ no parameters
rat1 = rat1 / rat2
******************************************/
Rational& Rational::operator/=(Rational& rat1)
{
	*this = *this / rat1;

	return *this;
}