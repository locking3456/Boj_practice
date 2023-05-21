#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int ans;
void solution(int row , int col , int size) {
	if (r == row && c == col) {
		cout << ans;
		return;
	}
	if (r >= row && r < row + size && c >= col && c < col +size)
	{
		solution(row, col, size / 2);//1��и�
		solution(row, col + size/2, size / 2); //2��и�
		solution(row + size/2, col, size / 2); // 3��и�
		solution(row + size / 2, col + size / 2, size / 2); //4��и�
	}
	else {
		ans += size * size;
	}
}
int main() {
	cin >> n >> r >> c;
	solution(0, 0, pow(2,n));
}