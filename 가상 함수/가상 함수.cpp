#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class First
{
public:

	virtual void FirstFunc()
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:

	virtual void SecondFunc()
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:

	virtual void ThirdFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	cout << fptr << ", " << sptr << ", " << tptr;
	delete tptr;
	
	return 0;
}
