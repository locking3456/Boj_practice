#include <iostream>
using namespace std;
int mat[21][21][21];
bool bmat[21][21][21] = { false , };
int solve(int a, int b, int c) {
	
	if (a <= 0 || b <= 0 || c <= 0) 
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return solve(20, 20, 20);
	else if (a < b && b < c)
	{
		if (bmat[a][b][c] ==true)
		{
			bmat[a][b][c] = true;
			return mat[a][b][c];
		}
		else {
			bmat[a][b][c] = true;
			return mat[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);

		}
	}
	else
	{
		if (mat[a][b][c] == true) {
			bmat[a][b][c] = true;
			return mat[a][b][c];
		}
		else {
			bmat[a][b][c] = true;
			return mat[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);

		}
	}

}
int main() {
	int a;
	int b;
	int c;
	while(true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) 
			break; 
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a,b,c) << endl;

	}
}