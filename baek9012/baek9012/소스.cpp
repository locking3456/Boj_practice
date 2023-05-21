#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int j;
	cin >> j;
	string s;
	for (int i = 0; i < j; i++)
	{
		cin >> s;
		stack <char> st;
		bool count = true;
		for (int k = 0; k < s.size(); k++)
		{
			if (s[k] == '(')
				st.push('(');
			else if (s[k] == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					count = false;
					break;
				}
			}
			
		}
		if (st.empty() && count)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}