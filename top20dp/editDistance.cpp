#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> number(m + 1, vector<int>(n + 1, 1));
		number[0][0] = 0;
		for (int i = 1; i <= m; ++i) number[i][0] = i;
		for (int i = 1; i <= n; ++i) number[0][i] = i;

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (word1[i-1] == word2[j-1])
				{
					number[i][j] = number[i-1][j-1];
				}
				else
				{
					number[i][j] = min(min(number[i-1][j], number[i][j-1]), number[i-1][j-1]) + 1;
				}
			}
		}
		return number[m][n];
	}
};

int main(void)
{
	Solution sol;
	cout << sol.minDistance("", "") << endl;
	cout << sol.minDistance("a", "") << endl;
	cout << sol.minDistance("", "a") << endl;
	cout << sol.minDistance("a", "a") << endl;
	cout << sol.minDistance("b", "a") << endl;
	cout << sol.minDistance("ab", "a") << endl;
	cout << sol.minDistance("a", "ab") << endl;
	cout << sol.minDistance("horse", "ros") << endl;
	cout << sol.minDistance("plasma", "altruism") << endl;
}
