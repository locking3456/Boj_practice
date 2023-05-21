#include <iostream>
using namespace std;
class Rect;
class Rectmanager
{
public:
	bool equals(Rect r, Rect s);
};
class Rect
{
	int width, height;
public:
	Rect(int width, int height)
	{
		this->width = width;
		this->height = height;
	};
	friend bool Rectmanager::equals(Rect r, Rect s);
};
bool Rectmanager::equals(Rect r, Rect s)
{
	if (r.width == s.width && r.height == s.height)
		return true;
	else
		return false;
};
int main()
{
	Rect a(3, 4), b(4, 5);
	Rectmanager man;
	if (man.equals(a, b))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
}