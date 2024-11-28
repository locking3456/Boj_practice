#include <iostream>
#include <vector>
#include <utility>
#define MAX_INT 2147483647
using namespace std;
int N, M;
vector<pair<int, int>> chickenPos;
bool isVisited[50] = { 0, };
vector<pair<int, int>> housePos;
vector<pair<int, int>> selectedChicken;
int minCityDistance=MAX_INT;
void calculateDistance() {
	int distanceOfCity = 0;
	for (int i = 0; i < housePos.size(); i++) {
		int minDistance = MAX_INT;
		for (int j = 0; j < selectedChicken.size(); j++) {
			int distance = abs(housePos[i].first - selectedChicken[j].first) + abs(housePos[i].second - selectedChicken[j].second);
			if (distance < minDistance) {
				minDistance = distance;
			}
		}
		distanceOfCity += minDistance;
	}
	if (distanceOfCity < minCityDistance) {
		minCityDistance = distanceOfCity;
	}
}
void selectChicken(int idx, int level) {
	if (level == M) {
		calculateDistance();
		return;
	}
	for (int i = idx; i < chickenPos.size(); i++) {
		if (!isVisited[i]) {
			isVisited[i] = true;
			selectedChicken.push_back(chickenPos[i]);
			selectChicken(i , level + 1);
			isVisited[i] = false;
			selectedChicken.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 2) {
				chickenPos.push_back(make_pair(i, j));
			}
			else if (tmp == 1) {
				housePos.push_back(make_pair(i, j));
			}
		}
	}
	selectChicken(0,0);
	cout << minCityDistance;
}