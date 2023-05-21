#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	Stack t;
	t.push(1);
	t.push(2);
	t.push(3);
	t.print();
	t.pop();
	t.print();
}
