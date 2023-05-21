#include <iostream>
using namespace std;
#define DEF_STACK_SIZE 20  //���ÿ� �������� ����Ʈ ���� ����
#include "Stack.h"
Stack::Stack() 
{
	this->size = DEF_STACK_SIZE;
	s = new int[this->size];
	top = -1; //���ÿ����� �ٴڰ��� �ǹ�
}
Stack::Stack(int size) 
{
	this->size = size;
	s = new int[size];
	top = -1;//������ ������ ���� �ٴ����� �ٲ�
}
void Stack::push(int k)  //������ top���� �ø��� ������ ���� �Ҵ�
{
	if (isFull() == 1)
		cout << "full";
	else 
	{

		top++;
		s[top] = k;
	}
}
void Stack::pop()  //�����̰���Ű�� ���� ���� �������� ���� ������� ������ ���� ����Ű�� index�� �ϳ��۾���
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
	if (top == size-1) //���ÿ��� ������ ���� index���� 1ŭ���� top�� ������index-1�� �� �� ��
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
		delete[] s;//������ �������ִ� �迭�� �޸𸮸� ��ȯ
}