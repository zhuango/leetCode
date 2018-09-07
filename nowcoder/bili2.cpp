#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void)
{
	int n;
	while (true)
	{
		int m, n;
		cin >> m >> n;
		if (m == -1 && n == -1) break;
		vector<vector<int>> num(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> num[i][j];
			}
		}
		stringstream s;
		int start = 0;
		while (m > start * 2 && n > start * 2)
		{
			int enda = n - 1 - start;
			int endb = m - 1 - start;
			for (int i = start; i <= enda; ++i)
			{
				s << num[start][i] << ",";
			}
			if (start < endb)
			{
				for (int i = start + 1; i <= endb; ++i)
				{
					s << num[i][enda] << ",";
				}
			}
			if (start < enda && start < endb)
			{
				for (int i = enda - 1; i >= start; --i)
				{
					s << num[endb][i] << ",";
				}
			}
			if (start < enda && start < endb - 1)
			{
				for (int i = endb - 1; i >= start + 1; --i)
				{
					s << num[i][start] << ",";
				}
			}
		    start++;
		}
		string res = s.str();
		cout << res.substr(0, res.size() - 1) << endl;
	}
	return 0;
}