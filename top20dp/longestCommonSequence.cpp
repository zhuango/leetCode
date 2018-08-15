#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int temp;
	vector<string> ss(2 * n);
	for (int i = 0; i < 2*n; i+=2)
	{
		cin >> temp >> temp;
		cin >> ss[i] >> ss[i + 1];
	}
	for (int i = 0; i < 2 * n; i+=2)
	{
		string s = ss[i];
		string t = ss[i + 1];
		vector<vector<int>> result(s.size() + 1, vector<int>(t.size() + 1, 0));
		for (int j = 0; j < s.size(); ++j)
		{
			for (int k = 0; k < t.size(); ++k)
			{
				result[j+1][k+1] = max(result[j][k+1], result[j+1][k]);
				if (s[j] == t[k]) result[j+1][k+1] = max(result[j+1][k+1], result[j][k] + 1);
			}
		}
		cout << result[s.size()][t.size()] << endl;
	}
}