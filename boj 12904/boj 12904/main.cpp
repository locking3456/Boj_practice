#include <iostream>
#include<string>        
#include<algorithm>
using namespace std;
int main() {
	string s, t;
	cin >> s;
	cin >> t;
	while (1) {
		if (s.size() == t.size()) {
			if (t == s) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			break;
		}
		if (t[t.size() - 1] == 'A') {
			t.pop_back();
		}
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
}
