#include <iostream>
#include "person.h"
using namespace std;
int main()
{
	person a(1, "������", "�д籸");
	person b(a);
	b.changeName("�����");
	a.print();
	b.print();
}