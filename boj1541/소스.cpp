#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	string num;
	bool Isminums=false;
	int result;
	cin >> input;
	result = 0;

	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || i == input.size()) {
			if (Isminums) {
				result -= stoi(num);
				num = "";
			}
			else {
				result += stoi(num);
				num = "";
			}
		}
		else {
			num += input[i];
		}
		if (input[i] == '-')
			Isminums = true;
	}

	cout << result;
}