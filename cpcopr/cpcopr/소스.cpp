#include <iostream>
using namespace std;
class Circle
{
private:
	int radius;
public:
	Circle(const Circle& c);
	Circle();
	Circle(int radius);
	double getarea();
};
Circle:: Circle(const Circle& c)
{
	this->radius = c.radius;
	cout << "���� ������ ���� radius= " << radius << endl;
}
Circl