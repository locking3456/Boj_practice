#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main()
{
	int testcase;
	int arraynum;
	int count=0;
	cin >> testcase;
	string command;
	string arrayfordeque;
	string imsistr;
	int imsi;
	deque<int>dg;
	int fn=-1;
	int en=-1;
	for (int i = 0; i < testcase; i++)//testcase�� �޾Ƽ� �̸� int�� ��ť������
	{
		bool reverse = true;//reverse�� �̿��� deque�� pop�� ������� �����ϱ� ���� ����
		count = 0;
		cin >> command;
		int sizeofcommand = command.size();//����� ����� �Ǻ�
		cin >> arraynum;
		cin >> arrayfordeque;
		int sizeofdeque = arrayfordeque.size();
		for (int j = 0; j < sizeofdeque; j++)
		{

			if (isdigit(arrayfordeque[j]))//string���� ������ �迭 ��ġ�� �Ի��ؼ� �̵��� ����
			{
				if (fn == -1 && en == -1)
				{
					fn = j;
					en = j;
				}
				else if (fn != -1)
				{
					en = j;
				}
			}
			else// ���ڰ� �ƴҶ��� �տ� �����ߴ� �迭�� ��ġ�� �̿��ؼ� ���� ����
			{
				if (fn != -1 && en != -1)
				{
					imsistr = arrayfordeque.substr(fn, en - fn + 1);
					imsi = atoi(imsistr.c_str());
					arraynum--;
					fn = -1;
					en = -1;
					dg.push_back(imsi);
				}
			}
		}
		if (arraynum != 0)//�Է¼��ڸ� �Է����ذſ� �����Ͱ� �ٸ����� ������ ����ϰ� �ٸ����̽����
		{
			cout << "error";
			continue;
		}
		else
		{
			for (int k = 0; k < sizeofcommand; k++)
			{
				if (command[k]=='R')
				{
					reverse = !reverse;
				}
				else//reverse�� true�� �տ��� pop false�� �ڿ��� pop
				{
					if (reverse == true)
					{
						if (!dg.empty())
							dg.pop_front();
						else
						{
							cout << "error\n";
							count = 1;
							break;
						}
					}
					if (reverse == false)
					{
						if (!dg.empty())
							dg.pop_back();
						else
						{
							cout << "error\n";
							count = 1;
							break;
						}
					}
					
				}
			}
		}
		if (count == 1)//dg�� �������� ���
			continue;
		if (reverse == true)
		{
			if (!dg.empty())
			{
				cout << '[';
				cout << dg.front();
				dg.pop_front();
				while (!dg.empty())
				{
					cout << ',';
					cout << dg.front();
					dg.pop_front();
				}
				cout << ']' << endl;
			}
			else
				cout << "[]";
		}
		if (reverse == false)
		{
			if (count == 1)
				continue;
			if (!dg.empty())
			{
				cout << '[';
				cout << dg.back();
				dg.pop_back();
				while (!dg.empty())
				{
					cout << ',';
					cout << dg.back();
					dg.pop_back();
				}
				cout << ']' << '\n';
			}
			else
				cout << "[]";
		}
	}

}