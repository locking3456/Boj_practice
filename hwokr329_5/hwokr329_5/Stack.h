#include<iostream>
#ifndef __STACK_H__
#define __STACK_H__
#define DEF_STACK_SIZE 20
using namespace std;
class Stack
{
	int size;
	int* s;
	int top;
public:
	Stack();
	Stack(int size);
	~Stack();
	
	void init() 
	{
		top = -1;
	}
	void push(int k);
	void pop();
	bool isEmpty();
	bool isFull();
	void print();
};
#endif


