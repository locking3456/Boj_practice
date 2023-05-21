#include <iostream>
using namespace std;
int rCubeSum(int n)
{
	if (n < 1)
	{
		return 0;
	}
	else
	{
		return n * n * n + rCubeSum(n - 1); //recursive call을 위해 순환함수를 작성 return값의 함수 자기자신을 같이 리턴해 줌으로서 조건에 만족하면 탈출
	}
}
int main()
{
	int x;
	cin >> x;
	cout<<rCubeSum(x);

}