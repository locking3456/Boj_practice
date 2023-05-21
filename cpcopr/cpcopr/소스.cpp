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
	cout << "복사 생성자 실행 radius= " << radius << endl;
}
Circl