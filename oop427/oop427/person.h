#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstring>
using namespace std;
class person {
private:
	int id;
	char* name;
	char* address;
public:
	person(int id=0, const char* name="none",const char* address="none")
	{
		this->id = id;
		int len = strlen(name);
		int adlen = strlen(address);
		this->name = new char[len + 1];
		this->address = new char[adlen + 1];
		strcpy(this->name, name);
		strcpy(this->address, address);
	}
	person(const person& a)
	{
		this->id = a.id;
		int len = strlen(a.name);
		int adlen = strlen(a.address);
		this->name = new char[len + 1];
		this->address = new char[adlen + 1];
		strcpy(this->name,a.name);
		strcpy(this->address,a.address);

	}
	void changeName(const char* name)
	{
		if (strlen(this->name) >= strlen(name))
		{
			strcpy(this->name, name);
		}
	}
	void changeAddress(const char* address)
	{
		if (strlen(this->address) >= strlen(address))
		{
			strcpy(this->address, address);
		}
	}
	void print()
	{
		cout << this->name << endl;
	}
};
#endif