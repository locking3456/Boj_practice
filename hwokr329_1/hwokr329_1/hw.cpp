#include <iostream>
using namespace std;
int main()
{
	int decinumber,mod,i,j,k,term;
	i = 0;
	j = 0;
	cout << "십진수를 입력하세요:";
	cin >> decinumber;
	term = decinumber; 
	k = decinumber;
	int *binary;
	while (decinumber >= 1) //10진수를 2진수로 계속 나누면서 binary배열에 bit수를 구하기위함
	{
		decinumber = decinumber / 2;
		i++;
	}
	binary = new int[i+1]; //\0을 포함하기 위해 i+1만큼의 동적 배열 크기를 구함
	while (term >= 1)
	{
		mod = term % 2;
		term = term / 2; //배열에다가 다시 10진수를 나눔으로서 배열에다가 2진수의 값들을 대입
		binary[j] = mod;
		j++;
	}
	cout << "십진수" << k << "은 이진수";
	for (i = j-1; i > -1; i--) //배열에 입력된 값을 다시 뒤의 index부터 거꾸로 출력해서 2진수출력
	{
		cout << binary[i];
	}
	cout << "입니다";
}