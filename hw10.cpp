/****
Edward Chen
703909636
The purpose of this assignment is to define a variety of set functions
****/

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//Takes the union of set elements
set<int> SetUnion(set<int> a, set<int> b);

//Takes the intersection of set elements
set<int> SetIntersection(set<int> a, set<int> b);

//Takes the set difference between the first and second arguments
set<int> SetDifference(set<int> a, set<int> b);

//Takes the symmetric difference betwene the first and second arguments
set<int> SymmetricDifference(set<int> a, set<int> b);

// Returns a set of sets of integers
set<set<int>> PowerSet(set<int> a);

// Takes the complement of the first argument with respect to the set
set<int> Complement(set<int> a, int n);

// Operator Overloading
set <int> operator + (set<int> a, set<int> b);
set <int> operator + (set<int> a, int b);
set <int> operator + (int a, set<int> b);
set <int> operator - (set<int> a, set<int> b);
set <int> operator - (set<int> a, int b);
set <int> operator - (int a, set<int> b);
set <int> operator ^ (set<int> a, set<int> b);
set <int> operator ^ (set<int> a, int b);
set <int> operator ^ (int a, set<int> b);
set <int> operator % (set<int> a, set<int> b);
set <int> operator % (set<int> a, int b);
set <int> operator % (int a, set<int> b);
set <int> operator ~ (set<int> a);

// I/O Operator Overloading
ostream& operator << (ostream& out, set<int>& a);
istream& operator >> (istream& in, set<int>& a);
ostream& operator << (ostream& out, set<set<int>>& a);

// Print function
void print(set<int> a);

int main()
{
	int input;
	set<int> A;
	set<int> B;
	set<int> result;
	set<set<int>> power_result;
	int highest_value;
	set<int>::iterator pos;

	cout << "Please input a set of distinct nonnegative numbers for a set (Enter -1 when you are finished):" << endl;
	cin >> A;
	cout << endl;
	
	cout << "We'll refer to this set as A from now on." << endl;
	cout << "A = " << A << endl;
	result = ~A;
	cout << "~A = ";
	cout << result <<endl << endl;
	
	cout << "Please input a set of distinct nonnegative numbers for a set (Enter -1 when you are finished):" << endl;
	cin >> B;
	cout << endl;
	
	cout << "We'll refer to this set as B from now on." << endl;
	cout << "B = " << B << endl;;
	result = ~B;
	cout << "~B = ";
	cout << result << endl << endl;

	cout << "Now we will do some arithmetic:" << endl;
	result = A + B;			// Finds the union of the two
	cout << "A+B = " << result << endl;
	result = A ^ B;			// Finds the intersection between the two
	cout << "A^B = " << result << endl;
	result = A - B;			// Finds the set difference between the two
	cout << "A-B = " << result << endl;
	result = B-A;			// Finds the set difference between the two
	cout << "B-A = " << result << endl;
	result = A % B;			// Finds the symmetric difference between the two
	cout << "A%B = " << result << endl << endl;
	
	result = SetIntersection(A,B);
	power_result = PowerSet(result);
	cout << "The power set of A^B is " << endl << power_result << endl << endl;

	return 0;
}

/**
Finds the union between two sets
@ parameter a is the first set
@ parameter b is the second set
@ returns the union
*/
set<int> SetUnion(set<int> a, set<int> b)
{
	set<int> result;
	set<int>::iterator it = a.begin();
	
	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	while (it != a.end()) {
		result.insert(*it);
		it++;
	}

	it = b.begin();
	while (it != b.end()) {
		result.insert(*it);
		it++;
	}
	return result;
}

/**
Finds the intersection
@ parameter a is the first set
@ parameter b is the second set
@ returns the intersection
*/
set<int> SetIntersection(set<int> a, set<int> b)
{
	set<int> result;

	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	set<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (b.count(*it) > 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}

/**
Finds the elements in the first set that are not in the second
@ parameters a is the first set
@ parameters b is the second set
@ returns the elements in a that is not in b
*/
set<int> SetDifference(set<int> a, set<int> b)
{
	set<int> result;

	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	set<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (b.count(*it) == 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}

/**
Finds the set of all that appear in one of A or B but not both
@ parameter a is the first set
@ parameter b is the second set
@ returns all the elements that appear in either A or B but not both
*/
set<int> SymmetricDifference(set<int> a, set<int> b)
{
	set<int> result;
	set<int> x;
	set<int> y;
	
	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	x = SetDifference(a,b);
	y = SetDifference(b,a);

	result = SetUnion(x,y);
	return result;
}

/**
Returns a set of sets of integers
@ paramter a is the set to be examined for all permutations
@ returns the set containing all permutations of parameter a
*/
set<set<int>> PowerSet(set<int> a)
{
	set<set<int>> result;

	// Creating the iterator to point to the last value
	set<int>::iterator pos = a.end();
	if (a.size() > 0)
		pos--;
	else
	{
		result.insert(a);
		return result;
	}
	
	// The subset that contains the set from first to second to last value
	set<int>::iterator first = a.begin();
	set<int> subset(first,pos);

	set<int> last_value;
	last_value.insert(*pos);
	set<set<int>> small = PowerSet(subset);
	set<set<int>>::iterator smallpos = small.begin(); // Points to first set in small


	while(smallpos != small.end())
	{
		result.insert(*smallpos);
		result.insert(SetUnion(*smallpos,last_value));
		smallpos++;
			
	}
	return result;
}

/**
Returns the elements that are not in set a
@ parameter a is set a
@ parameter n is the element with the highest value in the comparison set
@ returns the values that are in the comparison set but not in set a
*/
set<int> Complement(set<int> a, int n)
{
	set<int> result;
	set<int> omega;

	for (int i = 1; i <= n; i++)
		omega.insert(i);
	result = SetDifference(omega,a);
	return result;
}

/**
Overloads the operator + to find the union between set a and set b
@ parameter a is the first set
@ parameter b is the second set
@ returns the union of the set
*/
set <int> operator + (set<int> a, set<int> b)
{
	set<int> result;
	set<int>::iterator it = a.begin();
	
	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	while (it != a.end()) {
		result.insert(*it);
		it++;
	}

	it = b.begin();
	while (it != b.end()) {
		result.insert(*it);
		it++;
	}
	return result;
}

/**
Overloads the operator + to find the union between set a and int b
@ parameter a is the first set
@ parameter b is a single element with int b
@ returns the union of the set
*/
set <int> operator + (set<int> a, int b)
{
	set<int> result;
	set<int> single_element;
	single_element.insert(b);
	set<int>::iterator it = a.begin();
	
	// If one of the sets are empty
	if (a.size() == 0)
		return single_element;
	if (single_element.size() == 0)
		return a;

	while (it != a.end()) {
		result.insert(*it);
		it++;
	}

	it = single_element.begin();
	while (it != single_element.end()) {
		result.insert(*it);
		it++;
	}
	return result;
}

/**
Overloads the operator + to find the union between int a and set b
@ parameter a is a single element with int a
@ parameter b is the second set
@ returns the union of the set
*/
set <int> operator + (int a, set<int> b)
{
	set<int> result;
	set<int> single_element;
	single_element.insert(a);
	set<int>::iterator it = single_element.begin();
	
	// If one of the sets are empty
	if (single_element.size() == 0)
		return b;
	if (b.size() == 0)
		return single_element;

	while (it != single_element.end()) {
		result.insert(*it);
		it++;
	}

	it = b.begin();
	while (it != b.end()) {
		result.insert(*it);
		it++;
	}
	return result;
}
/**
Overloads the operator ^ to find the intersection between set a and set b
@ parameter a is the first set
@ parameter b is the second set
@ returns the intersection of the set
*/
set <int> operator ^ (set<int> a, set<int> b)
{
	set<int> result;

	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	set<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (b.count(*it) > 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}
/**
Overloads the operator ^ to find the intersection between set a and int b
@ parameter a is the first set
@ parameter b is a single element with int b
@ returns the intersection of the set
*/
set <int> operator ^ (set<int> a, int b)
{
	set<int> result;
	set<int> single_element;
	single_element.insert(b);

	// If one of the sets are empty
	if (a.size() == 0)
		return single_element;
	if (single_element.size() == 0)
		return a;

	set<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (single_element.count(*it) > 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}
/**
Overloads the operator ^ to find the intersection between int a and set b
@ parameter a is a single element with int a
@ parameter b is the second set
@ returns the intersection of the set
*/
set <int> operator ^ (int a, set<int> b)
{
	set<int> result;
	set<int> single_element;
	single_element.insert(a);

	// If one of the sets are empty
	if (single_element.size() == 0)
		return b;
	if (b.size() == 0)
		return single_element;

	set<int>::iterator it = single_element.begin();
	while (it != single_element.end()) {
		if (b.count(*it) > 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}
/**
Overloads the operator - to find the set difference between set a and set b
@ parameter a is the first set
@ parameter b is the second set
@ returns the set difference of the set
*/
set <int> operator - (set<int> a, set<int> b)
{
	set<int> result;

	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	set<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (b.count(*it) == 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}

/**
Overloads the operator - to find the set difference between set a and int b
@ parameter a is the first set
@ parameter b is a single element with int b
@ returns the set difference of the set
*/
set <int> operator - (set<int> a, int b)
{
	set<int> result;
	set<int> single_element;
	single_element.insert(b);

	// If one of the sets are empty
	if (a.size() == 0)
		return single_element;
	if (single_element.size() == 0)
		return a;

	set<int>::iterator it = a.begin();
	while (it != a.end()) {
		if (single_element.count(*it) == 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}

/**
Overloads the operator - to find the set difference between int a and set b
@ parameter a is a single element with int a
@ parameter b is the second set
@ returns the set difference of the set
*/
set <int> operator - (int a, set<int> b)
{
	set<int> result;
	set<int> single_element;
	single_element.insert(a);

	// If one of the sets are empty
	if (single_element.size() == 0)
		return b;
	if (b.size() == 0)
		return single_element;

	set<int>::iterator it = single_element.begin();
	while (it != single_element.end()) {
		if (b.count(*it) == 0) {
			result.insert(*it);
		}
		it++;
	}
	return result;
}

/**
Overloads the operator % to find the symmetric difference between set a and set b
@ parameter a is the first set
@ parameter b is the second set
@ returns the symmetric difference of the set
*/
set <int> operator % (set<int> a, set<int> b)
{
	set<int> result;
	set<int> x;
	set<int> y;
	
	// If one of the sets are empty
	if (a.size() == 0)
		return b;
	if (b.size() == 0)
		return a;

	x = SetDifference(a,b);
	y = SetDifference(b,a);

	result = SetUnion(x,y);
	return result;
}
/**
Overloads the operator % to find the symmetric difference between set a and int b
@ parameter a is the first set
@ parameter b is a single element with int b
@ returns the symmetric difference of the set
*/
set <int> operator % (set<int> a, int b)
{
	set<int> result;
	set<int> x;
	set<int> y;
	set<int> single_element;
	single_element.insert(b);
	
	// If one of the sets are empty
	if (a.size() == 0)
		return single_element;
	if (single_element.size() == 0)
		return a;

	x = SetDifference(a,single_element);
	y = SetDifference(single_element,a);

	result = SetUnion(x,y);
	return result;
}
/**
Overloads the operator % to find the symmetric difference between int a and set b
@ parameter a is a single element with int a
@ parameter b is the second set
@ returns the symmetric difference of the set
*/
set <int> operator % (int a, set<int> b)
{
	set<int> result;
	set<int> x;
	set<int> y;
	set<int> single_element;
	single_element.insert(a);
	
	// If one of the sets are empty
	if (single_element.size() == 0)
		return b;
	if (b.size() == 0)
		return single_element;

	x = SetDifference(single_element,b);
	y = SetDifference(b,single_element);

	result = SetUnion(x,y);
	return result;
}
/**
Overloads operator ~ to return the elements that are not in set a
@ parameter a is set a
@ returns the values that are in the comparison set but not in set a
*/
set <int> operator ~ (set<int> a)
{
	set<int>::iterator highest_value = a.end();
	highest_value--;
	int n = *highest_value;

	set<int> result;
	set<int> omega;

	for (int i = 1; i <= n; i++)
		omega.insert(i);
	result = SetDifference(omega,a);
	return result;
}

/**
Overloads operator << to output the set of elements in set form
@ parameter out is the output stream
@ parameter a is the set to output
@ returns the output in set form
*/
ostream& operator << (ostream& out, set<int>& a)
{
	out << "{";
	set<int>::iterator it = a.begin();
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		if (i == size-1)
			out << *it << "";
		else
			out << *it << ",";
		it++;
	}
	out << "}";
	return out;
}

/**
Overloads operator >> to input the set of elements in set form
@ parameter in is the input stream
@ parameter a is the set to output
@ returns the input in set form
*/
istream& operator >> (istream& in, set<int>& a)
{
	int input;

	while (in >> input)
	{
	if (input == -1)
		break;
	else
		a.insert(input);
	}
	return in;
}

/**
Overloads operator << to output the set of sets of elements in set form
@ parameter out is the output stream
@ parameter a is the set of sets to output
@ returns the output in set form
*/
ostream& operator << (ostream& out, set<set<int>>& a)
{
	out << "{";
	set<set<int>>::iterator it = a.begin();
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		if (i == size-1)
		{
			print(*it);
			out << "";
		}
		else
		{
			print(*it);
			out << ",";
		}
		it++;
	}
	out << "}";

	return out;
}

/**
Prints the set
*/
void print(set <int> a)
{
	cout << "{";
	set<int>::iterator it = a.begin();
	int size = a.size();
	//while (it != a.end()) 
	for (int i = 0; i < size; i++)
	{
		if (i == size-1)
			cout << *it << "";
		else
			cout << *it << ",";
		it++;
	}
	cout << "}";
}