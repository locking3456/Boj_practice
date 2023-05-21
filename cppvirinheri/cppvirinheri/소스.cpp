#include<iostream>
using namespace std;
class BaseIO
{
public:
	int mode;
};
class In :public BaseIO
{
public:
	int readPos;
};
class out :public BaseIO
{
public:
	int writePos;
};
class InOut : public In, public out
{
public:
	bool safe;
};
int main()
{
	InOut ioObj;
	ioObj.readPos = 10;
	ioObj.writePos = 20;
	ioObj.safe = true;
	ioObj.mode = 5;
}

