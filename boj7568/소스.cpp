#include <iostream>
using namespace std;
class dungchi
{
public:
	int weight;
	int height;
};
int main() {
	dungchi  dunglist[50];
	int rank[50];
	fill_n(rank, 50, 1);
	int peoplenum;
	cin >> peoplenum;
	for (int i = 0; i < peoplenum; i++) {
		cin >> dunglist[i].weight >> dunglist[i].height;
	}
	for (int i = 0; i < peoplenum; i++) {
		for (int j = 0; j < peoplenum; j++) {
			if (dunglist[i].height < dunglist[j].height && dunglist[i].weight < dunglist[j].weight)
				rank[i]++;
		}
	}
	for (int i = 0; i < peoplenum; i++) {
		cout << rank[i] << " ";
	}
}