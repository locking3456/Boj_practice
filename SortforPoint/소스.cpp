#include<stdio.h>
#include<algorithm>
using namespace std;
class Point {
public:
	int pointX;
	int pointY;
	Point(int x = 0, int y = 0) {
		pointX = x;
		pointY = y;
	}

};
bool compare(Point& a, Point& b)
{
	if (a.pointX < b.pointX) {
		return true;
	}
	else if (a.pointX == b.pointX) {
		if (a.pointY < b.pointY)
		{
			return true;
		}
		else
			return false;
	}
	else return false;
};
int main() {
	int num;
	scanf("%d ",&num);
	Point* array = new Point[num];
	int x, y;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &x,&y);
		array[i].pointX = x;
		array[i].pointY = y;
	}
	sort(array, array + num,compare);

	for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", array[i].pointX, array[i].pointY);
	}
}
