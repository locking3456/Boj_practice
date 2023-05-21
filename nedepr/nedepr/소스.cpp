#include <iostream>
using namespace std;
class Circle
{
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	Circle(const Circle& c);
	void setRadius(int r)
	{
		radius = r;
	}
	double getArea();
};
Circle::Circle()
{
	radius = 1;
	cout << "������ ���� radius= " << radius << endl;
}
Circle::Circle(int r)
{
	radius = r;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::~Circle()
{
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}
Circle::Circle(const Circle& c)
{
	this->radius = c.radius;
	cout << "���� ������ ���� radius= " << radius << endl;
}
double Circle::getArea()
{
	return 3.14 * radius * radius;
}
int main()
{
	//int* pint = new int;
	//if (!pint)
	//	return 0;
	//while (true)
	//{
	//	cout << "input num bigger than 0>>";
	//	cin >> *pint;
	//	Circle* pocircle = new Circle(*pint);
	//	cout << "���� ������ " << pocircle->getArea();
	//	delete pocircle;
	//}

	Circle src(30);
	Circle dest(src);
	cout << "��������= " << src.getArea() << endl;
	cout << "�纻����= " << dest.getArea() << endl;
}
