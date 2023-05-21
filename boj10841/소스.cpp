#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class PersonId {
public:
	int age;
	string name;
};
PersonId Idarray[100001];
bool compare(PersonId x, PersonId y)
{
	return x.age < y.age;
}
int main() {
	int x;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cin >> Idarray[i].age >> Idarray[i].name;
	}
	stable_sort(Idarray, Idarray + x, compare);
	for (int i = 0; i < x; i++)
	{
		cout << Idarray[i].age << " " << Idarray[i].name <<"\n";
	}
}