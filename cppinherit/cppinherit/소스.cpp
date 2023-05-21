#include <iostream>
using namespace std;
class answer
{
public:
	int ans;
};
class Adder:virtual public answer
{
protected:
	int add(int a, int b)
	{
		this->ans = a + b;
		return this->ans;
	}

};
class Substractor :virtual public answer
{
protected:
	int minus(int a, int b)
	{
		this->ans = a - b;
		return this->ans;
	}
};
class Calculator :public Adder, public Substractor
{
public:
	int calc(char op, int a, int b);
};
int Calculator::calc(char op, int a, int b)
{
	int res = 0;
	switch (op)
	{
	case  '+': res = add(a, b); break;
	case '-': res = minus(a, b); break;
	}
	return res;
}
int main()
{
	Calculator handcal;
	handcal.ans = 5;
	cout << "2+4= " << handcal.calc('+', 2, 4) << endl;
	cout << "100-8= " << handcal.calc('-', 100, 8) << endl;
}