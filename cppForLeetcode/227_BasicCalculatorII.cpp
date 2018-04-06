#include <string>
#include <stack>
#include <functional>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> number;
		stack<char> operators;
		map<char, function<int(int, int)>> opmapping;
		set<char> validOps = {'+', '-', '*', '/'};
		opmapping['+'] = [](int a, int b){return a + b;};
		opmapping['-'] = [](int a, int b){return a - b;};
		opmapping['*'] = [](int a, int b){return a * b;};
		opmapping['/'] = [](int a, int b){return a / b;};
		int n = s.size();
		int result = 0;
		int i = 0;
		int start = 0;
		while (i < n)
		{
			while(i < n && s[i] == ' ') i++;
			if (i == n) break;
			start = i;
			if (isdigit(s[i]))
			{
				while (i < n && isdigit(s[i])) i++;
				number.push(stoi(s.substr(start, i - start)));
				if (!operators.empty())
				{
					char top = operators.top();
					if (top == '*' || top == '/')
					{
						int opr1 = number.top();
						number.pop();
						int opr2 = number.top();
						number.pop();
						number.push(opmapping[top](opr2, opr1));
						operators.pop();
					}
				}
			}
			else
			{
				if (validOps.find(s[i]) == validOps.end()) return -1;
				operators.push(s[i]);
				i++;
			}
		}
		int tempResult = 0;
		while(!operators.empty())
		{
			char op = operators.top();

			int op0 = number.top();
			number.pop();
			if (number.empty()) break;
			int op1 = number.top();
			number.pop();
		cout << op << " " << op1 << " " << op0 << endl;
			number.push(opmapping[op](op1, op0));
			operators.pop();
		}
		return number.top();
	}
};

int main(void)
{
	Solution sol;
	cout << sol.calculate(" 2 *12 - 2  +   2 *12 - 3 / 2 ") << endl;
}