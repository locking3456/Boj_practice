#include <iostream>
using namespace std;
#define DEF_STACK_SIZE 20  //스택에 사이즈의 디폴트 값을 정의
#include "Stack.h"
Stack::Stack() 
{
	this->size = DEF_STACK_SIZE;
	s = new int[this->size];
	top = -1; //스택에서의 바닥값을 의미
}
Stack::Stack(int size) 
{
	this->size = size;
	s = new int[size];
	top = -1;//스택이 가리는 층이 바닥으로 바뀜
}
void Stack::push(int k)  //스택의 top층을 올리고 그층에 값을 할당
{
	if (isFull() == 1)
		cout << "full";
	else 
	{

		top++;
		s[top] = k;
	}
}
void Stack::pop()  //스택이가리키는 곳이 한층 낮아지며 값은 사라지지 않지만 값을 가리키는 index가 하나작아짐
{
	if (isEmpty() == 1) 
	{
		cout << "empty";
	}
	else
		top--;
}
bool Stack::isFull() 
{
	if (top == size-1) //스택에서 스택의 수가 index보다 1큼으로 top과 스택의index-1의 값 과 비교
		return 1;
}
bool Stack::isEmpty() 
{
	if (top == -1)
		return 1;

}
void Stack::print() 
{
	cout << "Stack contents, top to bottom:" << endl;
	for (int i = top; i >= 0; i--) 
	{
		cout << s[i] << endl;
	}
}
Stack::~Stack() 
{
	if(!s)
		delete[] s;//스택이 가지고있던 배열의 메모리를 반환
}