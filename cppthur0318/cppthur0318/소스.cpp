#include <iostream>
using namespace std;
class Rectangle {
	float width;
	float height;
public:
	Rectangle(float width = 1.0, float height = 1.0)
	{
		this->width = width; 
		this->height = height;
		cout << "������ ���� ����"<<height<<"�ʺ�"<<width<<endl;
	}
	~Rectangle()
	{
		cout << "�Ҹ��� ����" << endl;
	}
	float Area() {
		return (width * height);
	}
	float Perimeter() {
		return (2.0 * (width + height));
	}
	bool IsSquare() {
		if (width == height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
class Box {
	float width;
	float height;
public:
	Box(float width = 1.0, float height = 1.0,
	{
		this->width = width;
		this->height = height;
		cout << "������ ���� ����" << height << "�ʺ�" << width << endl;
	}
	~Box()
	{
		cout << "�Ҹ��� ����" << endl;
	}
	float Area() {
		return (width * height);
	}
	float Perimeter() {
		return (2.0 * (width + height));
	}
};
int main()
{
	Rectangle x(3.5,4.7);
	cout<<x.Perimeter()<<endl;
	cout << x.Area() << endl;;

}