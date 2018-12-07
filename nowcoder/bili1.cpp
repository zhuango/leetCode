#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	char c;
	vector<vector<int>> down(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j != n - 1)
				cin >> down[i][j] >> c;
			else
				cin >> down[i][j];
		}
	}
	vector<vector<int>> res(n, vector<int>(n, 0x7fffffff));
	res[n - 1][n - 1] = down[n - 1][n - 1];
	for (int i = 1; i < n; ++i)
	{
		res[n - 1][n - 1 - i] = down[n - 1][n - 1 - i] + res[n - 1][n - i];
	}
	for (int i = 1; i < n; ++i)
	{
		res[n - 1 - i][n - 1] = down[n - 1 - i][n - 1] + res[n - i][n - 1];
	}

	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = n - 2; j >= 0; --j)
		{
			res[i][j] = down[i][j] + min(res[i + 1][j], res[i][j + 1]);
		}
	}
	cout << res[0][0] << endl;

	return 0;
}