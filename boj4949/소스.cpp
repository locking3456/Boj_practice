#include <iostream>
#include<cstdio>
#include <string>
#include<stack>
using namespace std;

int main()
{
	string str;
	while (1)
	{
		getline(cin, str); 
		stack<char> a;
		if (str[0] == '.') break;

		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == '(') a.push('(');
			if (str[i] == '[') a.push('[');
			if (str[i] == ']')
			{
				if (!a.empty() && a.top() == '[') a.pop();
				else { printf("no\n"); break; } // "]hello[" 같은 예외 문장들 방지
			}

			if (str[i] == ')')
			{
				if (!a.empty() && a.top() == '(') a.pop();
				else { printf("no\n"); break; } // ")hello(" 같은 예외 문장들 방지
			}

			if (a.empty() && i == str.length() - 2) printf("yes\n"); 
			else if (!a.empty() && i == str.length() - 2) printf("no\n");
		}

	}
}