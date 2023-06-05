#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//중복 순열
int caseNum;
int arr[100000];
bool vectorIndexUsed[100000];
void DuplicatePermutation(int level, vector<int> caseVector) {
	if (level == caseNum) {
		for (int i = 0; i < caseNum; i++) {
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < caseVector.size(); i++) {
		arr[level] = caseVector[i];
		DuplicatePermutation(level + 1, caseVector);
	}
}


void Permutation(int level, vector<int> caseVector) {
	if (level == caseNum) {
		for (int i = 0; i < caseNum; i++) {
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < caseVector.size(); i++) {
		if (!vectorIndexUsed[i]) {
			vectorIndexUsed[i] = true;
			arr[level] = caseVector[i];
			Permutation(level + 1, caseVector);
			vectorIndexUsed[i] = false;
		}
	}
}

void Combination(int level, vector<int> caseVector, int beforeIndex) {
	if (level == caseNum) {
		for (int i = 0; i < caseNum; i++) {
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = beforeIndex; i < caseVector.size(); i++) {
		arr[level] = caseVector[i];
		Combination(level + 1, caseVector, beforeIndex + 1);
	}
}

void duplicateCombination(int level, vector<int> caseVector, int beforeIndex) {
	if (level == caseNum) {
		for (int i = 0; i < caseNum; i++) {
			cout << arr[i];
		}
		cout << endl;
		return;
	}
	for (int i = beforeIndex; i < caseVector.size(); i++) {
		arr[level] = caseVector[i];
		duplicateCombination(level + 1, caseVector, i);
	}
}
int main() {
	cin >> caseNum;
	vector<int> dupPermuTest = { 1,4,5,2 };
	DuplicatePermutation(0, dupPermuTest);
	cout << "====================================="<<endl;
	Permutation(0, dupPermuTest);
	cout << "====================================="<<endl;
	sort(dupPermuTest.begin(), dupPermuTest.end());
	Combination(0, dupPermuTest, 0);

}