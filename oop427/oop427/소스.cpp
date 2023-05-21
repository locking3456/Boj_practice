#include <iostream>
#include "person.h"
using namespace std;
int main()
{
	person a(1, "³ëÇö¼·", "ºÐ´ç±¸");
	person b(a);
	b.changeName("±è¼ö¹«");
	a.print();
	b.print();
}