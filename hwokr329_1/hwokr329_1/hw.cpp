#include <iostream>
using namespace std;
int main()
{
	int decinumber,mod,i,j,k,term;
	i = 0;
	j = 0;
	cout << "�������� �Է��ϼ���:";
	cin >> decinumber;
	term = decinumber; 
	k = decinumber;
	int *binary;
	while (decinumber >= 1) //10������ 2������ ��� �����鼭 binary�迭�� bit���� ���ϱ�����
	{
		decinumber = decinumber / 2;
		i++;
	}
	binary = new int[i+1]; //\0�� �����ϱ� ���� i+1��ŭ�� ���� �迭 ũ�⸦ ����
	while (term >= 1)
	{
		mod = term % 2;
		term = term / 2; //�迭���ٰ� �ٽ� 10������ �������μ� �迭���ٰ� 2������ ������ ����
		binary[j] = mod;
		j++;
	}
	cout << "������" << k << "�� ������";
	for (i = j-1; i > -1; i--) //�迭�� �Էµ� ���� �ٽ� ���� index���� �Ųٷ� ����ؼ� 2�������
	{
		cout << binary[i];
	}
	cout << "�Դϴ�";
}