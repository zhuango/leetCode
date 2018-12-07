#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

string dfs(vector<set<char>> &dics, set<string> &s, string &cur, int i)
{
	if (i == dics.size())
	{
		if (s.count(cur) != 0) return "-";
		else return cur;
	}
	for(char c : dics[i])
	{
		cur.push_back(c);
		string ss = dfs(dics, s, cur, i + 1);
		if (ss != "-") return ss;
		cur.pop_back();
	}
	return "-";
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	set<string> ss;
	vector<set<char>> dics(m);
	for(int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		ss.insert(s);
		
		for(int j = 0; j < m; ++j)
		{
			dics[j].insert(s[j]);
		}
	}
	string temp = "";
	cout << dfs(dics, ss, temp, 0) << endl;
	return 0;
}
