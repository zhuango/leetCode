#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef bool(*Comp)(int a, int b);

int main(void)
{
	Comp dd = [](int a, int b) { return a > b; };
	string s, t;
	cin >> s >> t;
	map<char, priority_queue<int, vector<int>, Comp>> mapping;
	int index = 0;
	for (char c : s)
	{
		if (mapping.count(c) == 0)
		{
			mapping[c] = priority_queue<int, vector<int>, Comp>(dd);
		}
		mapping[c].push(index);
		index += 1;
	}
	char old = ' ';
	index = -1;
	for (int i = 0; i < t.size(); ++i)
	{
		if (mapping.count(t[i]) == 0)
		{
			cout << "No" << endl;
			return 0;
		}
		else
		{
			int temp = mapping[t[i]].top();
			if (temp <= index)
			{
				cout << "No" << endl;
				return 0;
			}
			old = t[i];
			mapping[t[i]].pop();
			index = temp;
		}

	}
	cout << "Yes" << endl;
}