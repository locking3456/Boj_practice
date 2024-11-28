#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

vector<priority_queue < pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>>> inputData(101);
int parent[101];
vector<pair<float, float>> stars(101);
float starDistance;
float makeFloat(float x) {
	return round(100 * x) / 100;
}

float getDistance(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int findParent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = findParent(parent[x]);
}

void uni(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	parent[y] = x;
}

bool isSameParent(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x == y)
		return true;
	else
		return false;

}
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		float tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		stars[i] = { tmp1,tmp2 };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			float distance = getDistance(stars[i].first, stars[i].second, stars[j].first, stars[j].second);
			if (i == j)
				continue;
			inputData[i].push({ distance, j });

			
		}
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		int star1 = 1;
		while (!inputData[1].empty()) {
			int star2 = inputData[1].top().second;
			float cost = inputData[1].top().first;
			inputData[1].pop();

			if (!isSameParent(star1, star2)) {
				starDistance += cost;
				uni(star1, star2);
				while (!inputData[star2].empty()) {
					inputData[1].push({ inputData[star2].top().first, inputData[star2].top().second });
					inputData[star2].pop();
				}
				break;
			}
		}
	}

	cout << round(starDistance*100);
}