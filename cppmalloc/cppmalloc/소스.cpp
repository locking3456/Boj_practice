#include <iostream>
using namespace std;
class Statistics
{
public:
	int cnt;
	int size;
	int* s;
	Statistics(int size = 8, int cnt = 0)
	{
		s = new int[size];
		this->cnt = cnt;
	}
	bool operator!();
	Statistics& operator<<(int x);
	void operator ~();
};
bool Statistics::operator!()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Statistics& Statistics::operator<<( int x)
{
	this->s[this->cnt] = x;
	this->cnt += 1;
	return *this;
}
void Statistics::operator ~()
{
	for (int i = 0; i < cnt; i++)
	{
		cout << this->s[i] << endl;
	}

}
int main()
{
	Statistics stat;
	if (!stat)
	{
		cout << "현재 통계 데이타가 없습니다." << endl;
	}
	int x[5];
	cout << "5개의 정수를 입력하여라>>";
	for (int i = 0; i < 5; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < 5; i++)
	{
		stat << x[i];
	}
	stat << 100 << 200;
	~stat;

}