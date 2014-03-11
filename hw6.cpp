/****************************************************
Edward Chen
703909636
The purpose of this program is to let the user input as many points as desired, 
and then print them out in sorted order with the appropriate attributes.
February 14, 2013
****************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
	
	virtual int returnType();

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

	virtual int returnType();

private:
	string color;
};

class WeightedPoint2D : public Point2D {
public:
	// constructors
	WeightedPoint2D();
	WeightedPoint2D(double a, double b, double wt);

	// Gets-rs
	double getwt();

	// print functions
	virtual void print();

	virtual int returnType();

private:
	double weight;
};

bool compare (Point2D* a, Point2D* b);

int main() 
{

vector <Point2D*> points;
int num_select;
double x;
double y;
double wt;
string col;
//Point2D* a;
//Point2D* b;






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

Point2D type; 
for (int i = 0; i < points.size(); i++)
{
	type.returnType();
	sort (points.begin(),points.end(), compare);
}
// Prints out the selection
cout << "Your points in sorted order are " << endl;
cout << endl;
for (int i = 0; i < points.size(); i++)
{
	cout << i+1 << ": ";
	(*points[i]).print();
	//(*sort_points[i]).print();
	cout << endl;
}

for (int i = 0; i < points.size(); i++)
{
	delete points[i];
}

system ("pause");
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

/**
Returns the class type
@ no parameters
@ returns 1 which signifies Point2D
*/
int Point2D::returnType()
{
	return 1;
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
Returns the class type
@ no parameters
@ returns 2 which signifies ColorPoint2D
*/
int ColorPoint2D::returnType()
{
	return 2;
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
Accessor for private variable weight
@ no parameters 
@ gets private variable weight
*/
double WeightedPoint2D::getwt()
{
	return weight;
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

/**
Returns the class type
@ no parameters
@ returns 3 which signifies WeightedPoint2D
*/
int WeightedPoint2D::returnType()
{
	return 3;
}

/**
Compares the classes
@ parameter Point2D* a
@ parameter Point2D* b
@ returns 0
*/
bool compare (Point2D* a, Point2D* b)
{
	vector <Point2D*> sort_points;
	Point2D type;
	
	// Rules for comparison of Point2D class
	if (type.returnType() == 1)
	{
		//Point2D* a = dynamic_cast <Point2D*> (a);
		//Point2D* b = dynamic_cast <Point2D*> (b);
		if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) < sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			sort_points.push_back(a);
			return true;
		}
		else if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) > sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			//sort_points.push_back(b);
			return false;
		}	
		else if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) == sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			double angleA = atan2(a->gety(),a->getx());
			double angleB = atan2(b->gety(),b->getx());
			if (angleA < angleB)
				sort_points.push_back(a);
				return true;
			//else
				//sort_points.push_back(b);
				//return false;
		}
	}
	// Rules for comparison of ColorPoint2D class
	else if (type.returnType() == 2)
	{
		ColorPoint2D* a = dynamic_cast <ColorPoint2D*> (a);
		ColorPoint2D* b = dynamic_cast <ColorPoint2D*> (b);
		if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) < sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			sort_points.push_back(a);
			return true;
		}
		else if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) > sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			//sort_points.push_back(b);
			return false;
		}	
		else if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) == sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			string colA = a->getc();
			string colB = b->getc();
			if (colA < colB)
				sort_points.push_back(a);
				return true;
			//else 
				//sort_points.push_back(b);
				//return false;
		}
	}
	// Rules for comparison of WeightedPoint2D class
	else if (type.returnType() == 3)
	{
		WeightedPoint2D* a = dynamic_cast <WeightedPoint2D*> (a);
		WeightedPoint2D* b = dynamic_cast <WeightedPoint2D*> (b);
		if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) < sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			sort_points.push_back(a);
			return true;
		}
		else if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) > sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			//sort_points.push_back(b);
			return false;
		}	
		else if (sqrt(pow(a->getx(),2) +pow(a->gety(),2)) == sqrt(pow(b->getx(),2) +pow(b->gety(),2)))
		{
			double colA = a->getwt();
			double colB = b->getwt();
			if (colA < colB)
				sort_points.push_back(a);
				return true;
			//else 
				//sort_points.push_back(b);
				//return false;
		}
	}
	

	return true;
}
