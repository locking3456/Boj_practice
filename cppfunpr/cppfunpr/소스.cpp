#include <iostream>
using namespace std;
void chnum(int* a, int* b);
int main()
{
	int m = 2, n = 9;
	chnum(&m, &n);
	cout << m << ' ' << n;

}
void chnum(int* a, int* b)
{
	int tmp;
	tmp = *a + 2;
	*a = *b;
	*b = tmp;
}