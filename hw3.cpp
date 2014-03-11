/****************************************************
Edward Chen
703909636
The purpose of this program is to let the user input as many points as desired, 
and then print them out in order with the appropriate attributes.
January 25, 2012
****************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Point2D {
public:
	// Constructors
	Point2D();
	Point2D(double a, double b);

	// Gets-rs
	double getx();
	double gety();

	// Print functions
	virtual void print();
	

private:
	double x;
	double y;
};



class ColorPoint2D : public Point2D {
public:
	// Constructors
	ColorPoint2D();
	ColorPoint2D(double a, double b, string col);
	ColorPoint2D(Point2D p, string col);

	// Get-r
	string getc();

	// Print
	virtual void print();
private:
	string color;
};

class WeightedPoint2D : public Point2D {
public:
	// constructors
	WeightedPoint2D();
	WeightedPoint2D(double a, double b, double wt);

	// print functions
	virtual void print();

private:
	double weight;
};


int main() 
{

vector <Point2D*> points;
int num_select;
double x;
double y;
double wt;
string col;


cout << "Welcome to Point Printer! You can create three different kinds of points: " << endl;
cout << endl;
cout << "1. Point2D, e.g., (2,6.5)" << endl;
cout << "2. ColorPoint2D, e.g., blue(-4.5,3.5)" << endl;
cout << "3. WeightedPoint2D, e.g., .12(3.6,8.7)" << endl;
cout << endl;
cout << "Enter 0 when you are finished. " << endl;
cin >> num_select;

while (num_select != 0)
{
	switch (num_select)
	{
	case 1: // Directs the user to Point2D 
		cout << "Selection: 1" << endl;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		points.push_back(new Point2D(x,y));
		break;
	case 2: // Directs the user to ColorPoint2D
		cout << "Selection: 2" << endl;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << "color = ";
		cin.ignore();
		getline (cin,col);
		points.push_back(new ColorPoint2D(x,y,col));
		break;
	case 3: // Directs the user to WeightedPoint2D
		cout << "Selection: 3" << endl;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << "weight = ";
		cin >> wt;
		points.push_back(new WeightedPoint2D(x,y,wt));
		break;
	default: // Ends the selection process
		cout << "Selection: 0";
		break;
	}
	cin >> num_select;
}
cout<<endl;

// Prints out the selection
cout << "Your points are " << endl;
cout << endl;
for (int i = 0; i < points.size(); i++)
{
	cout << i+1 << ": ";
	(*points[i]).print();
	cout << endl;
}

for (int i = 0; i < points.size(); i++)
{
	delete points[i];
}


return 0;

}


/** Default Constructor */
Point2D::Point2D() 
{ 
	x = 0; 
	y = 0; 
	return;
}

/** 
Constructor with parameters
@param a
@param b
@param col 
@returns (double a, double b)
*/
Point2D::Point2D(double a, double b) 
{ 
	x = a; 
	y = b; 
	return;
}

/** 
Accessor for private variable x
@ no parameters 
@ gets private variable x
*/
double Point2D::getx() 
{ 
	return x;
}

/** 
Accessor for private variable y
@ no parameters 
@ gets private variable y
*/
double Point2D::gety() 
{ 
	return y;
}

/** 
Prints Point2D
@ no parameters 
@ prints Point2D
*/
void Point2D::print() 
{
	cout<<"("<<x<<","<<y<<")";
	return;
}


/** Default constructor */
ColorPoint2D::ColorPoint2D() 
{ 
	color = "";
	return ;
}

/** 
Constructor with parameters
@ param a
@ param b
@ param col 
@ returns color(double a, double b)
*/
ColorPoint2D::ColorPoint2D(double a, double b, string col): Point2D(a,b)
{
	color = col;
	return;
}

/** 
Accessor for private variable color
@ no parameters 
@ gets private variable color
*/
string ColorPoint2D::getc() 
{ 
	return color; 
}

/** 
Prints ColorPoint2D
@ no parameters 
@ prints ColorPoint2D
*/
void ColorPoint2D::print() 
{
	cout<<color;
	Point2D::print();
	return;
}

/** 
Constructor with parameters
@ param a
@ param b
@ param col 
@ returns weight(double a, double b)
*/
WeightedPoint2D::WeightedPoint2D(double a, double b, double wt) : Point2D(a,b) 
{
	weight = wt;
}

/** 
Prints ColorPoint2D
@ no parameters 
@ prints ColorPoint2D
*/
void WeightedPoint2D::print() 
{
	cout<<weight;
	Point2D::print();
	return;
}