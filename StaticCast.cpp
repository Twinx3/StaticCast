#include <iostream>

using namespace std;

class Base
{

public:
	int val=0;
	Base()
	{
		val = 1;
	}
	void Res() {
		cout << "Base type\n";
	}

	void Base_Res() {
		cout << "Base_Res type\n";
	}
};


class DerivedA : public Base
{
public:
	DerivedA()
	{
		val = 2;
	}
	void Res()
	{
		cout << "DerivedA type\n";
	}

	void DerivedA_Res() {
		cout << "DerivedA_Res type\n";
	}
};


class DerivedB : public Base
{
public:
	DerivedB()
	{
		val = 3;
	}
	void Res()
	{
		cout << "DerivedB type\n";
	}

	void DerivedB_Res() {
		cout << "DerivedB_Res type\n";
	}
};

void DetermineType(Base* base)
{
	Base* Try = dynamic_cast<Base*>(base);
	Try->Res();
}

template<typename Class>
void DetermineTypeStatic(Class* base)
{
	Class* Try = static_cast<Class*>(base);
	Try->Res();
}

void CoutBase(Base* base)
{
	int* ptr = (int*)base;
	if (base->val == 1)
	{
		cout << "this is Base class" << endl;
	}
	else if (base->val == 2)
	{
		cout << "this is DerivedA class" << endl;
	}
	else
	{
		cout << "this is DerivedB class" << endl;
	}
}

int main()
{
	cout << "------------------" << endl;

	DetermineType(new Base); //Base type
	DetermineType(new DerivedA); //Base type
	DetermineType(new DerivedB); //Base type

	cout << "------------------" << endl;

	DetermineTypeStatic(new Base); //Base type
	DetermineTypeStatic(new DerivedA); //DerivedA type
	DetermineTypeStatic(new DerivedB); //DerivedB type 

	cout << "------------------" << endl;

	CoutBase(new Base);
	CoutBase(new DerivedA);
	CoutBase(new DerivedB);

	cout << "------------------" << endl;
	
}