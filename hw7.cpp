/**************************************
Edward Chen
703909636
February 19, 2013
This program will take integers as input and return the binary equivalent
****************************************/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class BinaryInteger
{
public:
	// Constructors
	BinaryInteger();
	BinaryInteger(int x);
	BinaryInteger(vector <bool> input, bool sign);

	// Print functions
	void print();

	// Operator Overloading
	BinaryInteger& operator <<= (int a);
	BinaryInteger& operator >>= (int a);
	BinaryInteger& operator << (int a);
	BinaryInteger& operator >> (int a);
	

private:
	vector <bool> BinaryNum;
	bool sign;
	void CleanUp();

	//Friends
	friend BinaryInteger operator + (BinaryInteger a, BinaryInteger b);
	friend BinaryInteger operator - (BinaryInteger a, BinaryInteger b);
	friend BinaryInteger operator & (BinaryInteger a, BinaryInteger b);
	friend BinaryInteger operator | (BinaryInteger a, BinaryInteger b);
	friend BinaryInteger operator ^ (BinaryInteger a, BinaryInteger b);
	friend BinaryInteger operator ~ (BinaryInteger a);
	friend ostream& operator << (ostream& out, BinaryInteger a);
	friend istream& operator >> (istream& in, BinaryInteger a);
	friend int bin2dec(BinaryInteger b);
};

// Non-member Operator Overloading
	BinaryInteger operator + (BinaryInteger a, BinaryInteger b);
	BinaryInteger operator - (BinaryInteger a, BinaryInteger b);
	BinaryInteger operator & (BinaryInteger a, BinaryInteger b);
	BinaryInteger operator | (BinaryInteger a, BinaryInteger b);
	BinaryInteger operator ^ (BinaryInteger a, BinaryInteger b);
	BinaryInteger operator ~ (BinaryInteger a);
	ostream& operator << (ostream& out, BinaryInteger a);
	istream& operator >> (istream& in, BinaryInteger a);

//Conversions
	vector<bool> dec2bin(int n);
	int bin2dec(vector<bool> b); 

void main()
{
	int n;
	int m;
	int r = 0;
	vector <bool> bin;
	BinaryInteger total;
	bool sign;

	cout << "Please input an integer n: ";
	cin >> n;
	cout << "The binary representation for n is: " << BinaryInteger(n);
	//BinaryInteger(n).print(); 
	cout << "\nPlease input an integer m: ";
	cin >> m;
	cout << "The binary representation for m is: " << BinaryInteger(m);
	//BinaryInteger(m).print();
	cout << "\nPlease input binary representation, first bit indicates sign (enter -1 when finished): " << endl;
	if (r = 1)
		sign = 1;
	else 
		sign = 0;
	while (r != -1)
	{
		cin >> r;
		bin.push_back(r);
	}
	cout << "Your integer value for r is: " << bin2dec(bin) << endl;
	cout << "n = " << n << " = " << BinaryInteger(n); 
	cout << endl;
	
	BinaryInteger nBinInt(n);
	BinaryInteger negated_nBinInt = ~nBinInt;

	cout << "~n = " << bin2dec(negated_nBinInt) << " = " << negated_nBinInt; 
	cout << endl;
	total = BinaryInteger(n) + BinaryInteger(m); 
	cout << "n+m = " << n+m << " = " << total; 
	cout << endl;
	total = BinaryInteger(n) & BinaryInteger(m);
	cout << "n&m = " << total; 
	cout << endl;
	total = BinaryInteger(n) ^ BinaryInteger(m);
	cout << "n^r = " <<  " = " << total; 
	cout << endl;
	cout << "2r = " << (BinaryInteger(r)>>(1)) << " = " << BinaryInteger(r);
	cout << endl;
	total = BinaryInteger(n) - BinaryInteger(m);
	cout << "n-m = " << n-m << " = " << total;
	cout << endl;
	total = BinaryInteger(n) ^ BinaryInteger(m);
	cout << "n|m = "  << " = " << total;
	cout << "256 * n = " << (BinaryInteger(n)>>(8)) << " = " << BinaryInteger(n);
	cout << "n/8 = " << (BinaryInteger(n)<<(1)) << " = " << BinaryInteger(n);

	system ("pause");

}

/**
@
@
***/
BinaryInteger::BinaryInteger()
{
	sign = 0;
	BinaryNum.push_back(0);
}

/**
@
@
***/
BinaryInteger::BinaryInteger(int x)
{
	if (x < 0)
	{
		x = x * -1;
		sign = 1;
	}
	while (x > 0)
	{
		int remainder = x % 2;
		if (remainder == 1)
			BinaryNum.push_back(1);
		else
			BinaryNum.push_back(0);
		x = x / 2;
	}
}

/**
@
@
***/
BinaryInteger::BinaryInteger(vector <bool> input, bool sign1)
{
	BinaryNum = input;
	sign = sign1;
}

/**
@
@
***/
void BinaryInteger::print()
{
	if (sign == 1)
		cout << "-";
	cout << "(";
	for(int i = BinaryNum.size()-1; i >=0; i--)
	{
		cout << BinaryNum[i];
		if (i!=0)
			cout << ",";
		else
			continue;
	}
	cout << ")";
}

BinaryInteger& BinaryInteger::operator <<= (int a)
{
	BinaryInteger c;
	return c;
}
	
BinaryInteger& BinaryInteger::operator >>= (int a)
{
	BinaryInteger c;
	return c;
}

BinaryInteger& BinaryInteger::operator << (int a)
{
	int n = BinaryNum.size();
	if (BinaryNum[n-1] == 0) // if number is positive
	{
		sign = 0;
		BinaryNum.erase(BinaryNum.begin(),BinaryNum.begin()+a);
		while (BinaryNum.size() != n)
			BinaryNum.push_back(0);
	}
	else
		sign = 1;
		for (int i = 0; i < BinaryNum.size(); i++)
		{
			if (BinaryNum[i] == 1)
				BinaryNum[i] = 0;
			else
				BinaryNum[i] = 1;
		}
		BinaryNum[BinaryNum.size()-1] = BinaryNum[BinaryNum.size()-1] + 1;
		if (BinaryNum[BinaryNum.size()-1] == 2)
		{
			BinaryNum[BinaryNum.size()-1] = 0;
			BinaryNum.push_back (1);
		}
		if (BinaryNum[BinaryNum.size()-1] == 3)
		{
			BinaryNum[BinaryNum.size()-1] = 1;
			BinaryNum.push_back (1);
		}
		
		BinaryNum.erase(BinaryNum.begin(),BinaryNum.begin()+a);
		while (BinaryNum.size() != n)
			BinaryNum.push_back(0);
	
	return BinaryInteger(BinaryNum,sign);
}

BinaryInteger& BinaryInteger::operator >> (int a)
{
	int n = BinaryNum.size();
	if (BinaryNum[n-1] == 0) // if number is positive
	{
		sign = 0;
		BinaryNum.erase(BinaryNum.begin(),BinaryNum.begin()+a);
		while (BinaryNum.size() != n)
			BinaryNum.push_back(0);
	}
	else
		sign = 1;
	// Finding two's complement representation to figure out value
		for (int i = 0; i < BinaryNum.size(); i++)
		{
			if (BinaryNum[i] == 1)
				BinaryNum[i] = 0;
			else
				BinaryNum[i] = 1;
		}
		BinaryNum[BinaryNum.size()-1] = BinaryNum[BinaryNum.size()-1] + 1;
		if (BinaryNum[BinaryNum.size()-1] == 2)
		{
			BinaryNum[BinaryNum.size()-1] = 0;
			BinaryNum.push_back (1);
		}
		if (BinaryNum[BinaryNum.size()-1] == 3)
		{
			BinaryNum[BinaryNum.size()-1] = 1;
			BinaryNum.push_back (1);
		}
		// bit shifting
		BinaryNum.erase(BinaryNum.begin(),BinaryNum.begin()+a);
		while (BinaryNum.size() != n)
			BinaryNum.push_back(0);
	
	return BinaryInteger(BinaryNum,sign);
}

BinaryInteger operator + (BinaryInteger a, BinaryInteger b)
{
	bool signA = a.sign;
	bool signB = b.sign;
	bool signC;
	vector <bool> total;
	int carry = 0;
	int result;
		
	// Determine which has the bigger length and make both lengths equal
	if (a.BinaryNum.size() > b.BinaryNum.size())
	{
		while (b.BinaryNum.size() != a.BinaryNum.size())
			b.BinaryNum.push_back(0);
	}
	else
		while (a.BinaryNum.size() != b.BinaryNum.size())
			a.BinaryNum.push_back(0);
	
	// If its negative, change all binary values from 0 to 1 and 1 to 0
	if (signA == 1)
	{
		for (int i = 0; i < a.BinaryNum.size(); i++)
		{
			if (a.BinaryNum[i] == 1)
				a.BinaryNum[i] = 0;
			else
				a.BinaryNum[i] = 1;
		}
		a.BinaryNum[a.BinaryNum.size()-1] = a.BinaryNum[a.BinaryNum.size()-1] + 1;
		if (a.BinaryNum[a.BinaryNum.size()-1] == 2)
		{
			a.BinaryNum[a.BinaryNum.size()-1] = 0;
			a.BinaryNum.push_back (1);
		}
		if (a.BinaryNum[a.BinaryNum.size()-1] == 3)
		{
			a.BinaryNum[a.BinaryNum.size()-1] = 1;
			a.BinaryNum.push_back (1);
		}
	}
	if (signB == 1)
	{
		for (int i = 0; i < b.BinaryNum.size(); i++)
		{
			if (b.BinaryNum[i] == 1)
				b.BinaryNum[i] = 0;
			else
				b.BinaryNum[i] = 1;
		}
		b.BinaryNum[b.BinaryNum.size()-1] = b.BinaryNum[b.BinaryNum.size()-1] + 1;
		if (b.BinaryNum[b.BinaryNum.size()-1] == 2)
		{
			b.BinaryNum[b.BinaryNum.size()-1] = 0;
			b.BinaryNum.push_back (1);
		}
		if (b.BinaryNum[b.BinaryNum.size()-1] == 3)
		{
			b.BinaryNum[b.BinaryNum.size()-1] = 1;
			b.BinaryNum.push_back (1);
		}
	}

	// Adding the two vectors
	for (int i = 0; i < a.BinaryNum.size(); i++)
		total.push_back(0);
	for (int i = 0; i < a.BinaryNum.size(); i++)
	{
		result =a.BinaryNum[i] + b.BinaryNum[i] + carry;
		if (result < 2)
			total[i] = result;
		if (result == 2)
		{
			total[i] = 0;
			carry = 1;
		}
		if (result == 3)
		{
			total[i] = 1;
			carry = 1;
		}
	}
	if (total[total.size()-1] == 1)
		signC = 1;
	else 
		signC = 0;

	return BinaryInteger (total,signC);
}



BinaryInteger operator - (BinaryInteger a, BinaryInteger b)
{
	bool signA = a.sign;
	bool signB = b.sign;
	bool signC;
	vector <bool> total;
	int carry = 0;
	int result;
	
	// Determine which has the bigger length and make both lengths equal
	if (a.BinaryNum.size() > b.BinaryNum.size())
	{
		while (b.BinaryNum.size() != a.BinaryNum.size())
			b.BinaryNum.push_back(0);
	}
	else
		while (a.BinaryNum.size() != b.BinaryNum.size())
			a.BinaryNum.push_back(0);
	
	// Changing Binary b to negative to single out b 
	for (int i = 0; i < b.BinaryNum.size(); i++)
		{
			if (b.BinaryNum[i] == 1)
				b.BinaryNum[i] = 0;
			else
				b.BinaryNum[i] = 1;
		}
		b.BinaryNum[b.BinaryNum.size()-1] = b.BinaryNum[b.BinaryNum.size()-1] + 1;
		if (b.BinaryNum[b.BinaryNum.size()-1] == 2)
		{
			b.BinaryNum[b.BinaryNum.size()-1] = 0;
			b.BinaryNum.push_back (1);
		}
		if (b.BinaryNum[b.BinaryNum.size()-1] == 3)
		{
			b.BinaryNum[b.BinaryNum.size()-1] = 1;
			b.BinaryNum.push_back (1);
		}
	

	// Adding the two vectors. ex: x-y -> x + (-y)
	for (int i = 0; i < a.BinaryNum.size(); i++)
		total.push_back(0);
	for (int i = 0; i < a.BinaryNum.size(); i++)
	{
		result =a.BinaryNum[i] + b.BinaryNum[i] + carry;
		if (result < 2)
			total[i] = result;
		if (result == 2)
		{
			total[i] = 0;
			carry = 1;
		}
		if (result == 3)
		{
			total[i] = 1;
			carry = 1;
		}
	}
	// determine the sign of the total
	if (total[total.size()-1] == 1)
		signC = 1;
	else 
		signC = 0;

	return BinaryInteger (total,signC);
}


BinaryInteger operator & (BinaryInteger a, BinaryInteger b)
{
	vector <bool> total;
	bool signC;

	// Determine which has the bigger length and make both lengths equal
	if (a.BinaryNum.size() > b.BinaryNum.size())
	{
		while (b.BinaryNum.size() != a.BinaryNum.size())
			b.BinaryNum.push_back(0);
	}
	else
		while (a.BinaryNum.size() != b.BinaryNum.size())
			a.BinaryNum.push_back(0);

	// Testing if true/false
	for (int i = 0; i < a.BinaryNum.size(); i++)
	{
		if (a.BinaryNum[i] == 1 && b.BinaryNum[i] == 1)
			total.push_back(1);
		else
			total.push_back(0);
	}
	// Checking sign value
	if (total[total.size()-1] == 1)
		signC = 1;
	else 
		signC = 0;
	return BinaryInteger (total,signC);
}
BinaryInteger operator | (BinaryInteger a, BinaryInteger b)
{
	vector <bool> total;
	bool signC;

	// Determine which has the bigger length and make both lengths equal
	if (a.BinaryNum.size() > b.BinaryNum.size())
	{
		while (b.BinaryNum.size() != a.BinaryNum.size())
			b.BinaryNum.push_back(0);
	}
	else
		while (a.BinaryNum.size() != b.BinaryNum.size())
			a.BinaryNum.push_back(0);

	// Testing if true/false
	for (int i = 0; i < a.BinaryNum.size(); i++)
	{
		if (a.BinaryNum[i] == b.BinaryNum[i] == 0)
			total.push_back(0);
		else
			total.push_back(1);
	}
	// Checking sign value
	if (total[total.size()-1] == 1)
		signC = 1;
	else 
		signC = 0;
	return BinaryInteger (total,signC);
}

BinaryInteger operator ^ (BinaryInteger a, BinaryInteger b)
{
	vector <bool> total;
	bool signC;

	// Determine which has the bigger length and make both lengths equal
	if (a.BinaryNum.size() > b.BinaryNum.size())
	{
		while (b.BinaryNum.size() != a.BinaryNum.size())
			b.BinaryNum.push_back(0);
	}
	else
		while (a.BinaryNum.size() != b.BinaryNum.size())
			a.BinaryNum.push_back(0);

	// Testing if true/false
	for (int i = 0; i < a.BinaryNum.size(); i++)
	{
		if (a.BinaryNum[i] == b.BinaryNum[i] == 1 || 0)
			total.push_back(0);
		else
			total.push_back(1);
	}
	// Checking sign value
	if (total[total.size()-1] == 1)
		signC = 1;
	else 
		signC = 0;
	return BinaryInteger (total,signC);
}

BinaryInteger operator ~ (BinaryInteger a)
{
	for (int i = 0; i < a.BinaryNum.size(); i++)
		{
			//cout << "\ncurrent number is: " << a.BinaryNum[i];
			if (a.BinaryNum[i] == 1)
			{
				a.BinaryNum[i] = 0;
				//cout << "\ncurrent number is now changed to: " << a.BinaryNum[i];
			}
			else
			{
				a.BinaryNum[i] = 1;
				//cout << "\ncurrent number is now changed to: " << a.BinaryNum[i];
			}
		}
	return a;
}

ostream& operator << (ostream& out, BinaryInteger a)
{
	if (a.sign == 1)
		cout << "-";
	cout << "(";
	for(int i = a.BinaryNum.size()-1; i >=0; i--)
	{
		cout << a.BinaryNum[i];
		if (i!=0)
			cout << ",";
		else
			continue;
	}
	cout << ")";
	
	/*
	int n=0;
    int sz = (int)a.BinaryNum.size();
    int power = 1;

    for(int i=sz -1;i<0;i--) 
	{
    	n += power*a.BinaryNum[i];
		power<<=1;
    }
    
    cout << n;
	*/

	return out;
}

istream& operator << (istream& in, BinaryInteger a)
{
	vector<bool> val(1,false);  // Start with one value
	int n;

	if(cin >> n==0) 
		val[0]=0; // 0 return vector with 0
	else if(n==1) 
	{   // 1 return vector with 1
		val[0]=1;
	}

	// n >= 2
	int power = 0;
	int p=1;
    

    while((p<<=1) <= n) 
	{
        power++;
		val.push_back(0);
    }

    p>>=1;
    val[power]=1;

	n = n - p;
    power--;
    p>>=1;

	while(n>0) 
	{
		while(n<p) 
		{
            power--;
			p>>=1;
		}
        
        val[power]=1;
        n -= p;
    }
    
    return in;
}

vector<bool> dec2bin(int n)
{
	vector<bool> val(1,false);  // Start with one value

	if(n==0) return val; // 0 return vector with 0
	else if(n==1) {      // 1 return vector with 1
		val[0]=1;
		return val;
	}

	// n >= 2
	int power = 0;
	int p=1;
    

    while((p<<=1) <= n) {
        power++;
		val.push_back(0);
    }

    p>>=1;
    val[power]=1;

	n = n - p;
    power--;
    p>>=1;

	while(n>0) 
	{
		while(n<p) 
		{
            power--;
			p>>=1;
		}
        
        val[power]=1;
        n -= p;
    }
    
    
    return val;
}

int bin2dec(BinaryInteger b)
{
	int n=0;
    int sz = (int)b.BinaryNum.size();
    int power = 1;

	//for(int i=sz -1;i<0;i--)
    for(int i=0;i<sz;i++) 
	{
    	n += power*b.BinaryNum[i];
		power<<=1;
    }
    
    return n;
}

void BinaryInteger::CleanUp()
{
	while (BinaryNum.back() == 0)
		BinaryNum.pop_back();
}