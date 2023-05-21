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
	for (int i = 0; i < testcase; i++)//testcase를 받아서 이를 int형 데큐에넣음
	{
		bool reverse = true;//reverse를 이용해 deque에 pop을 어디서할지 결정하기 위한 변수
		count = 0;
		cin >> command;
		int sizeofcommand = command.size();//명령의 사이즈를 판별
		cin >> arraynum;
		cin >> arrayfordeque;
		int sizeofdeque = arrayfordeque.size();
		for (int j = 0; j < sizeofdeque; j++)
		{

			if (isdigit(arrayfordeque[j]))//string에서 숫자의 배열 위치를 게산해서 이들을 저장
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
			else// 숫자가 아닐때는 앞에 저장했던 배열의 위치를 이용해서 수를 추출
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
		if (arraynum != 0)//입력숫자를 입력해준거와 데이터가 다를때는 에러를 출력하고 다른케이스계산
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
				else//reverse가 true면 앞에서 pop false면 뒤에서 pop
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
		if (count == 1)//dg가 빌때까지 출력
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