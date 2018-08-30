#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> qi(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> qi[i];
	}
	vector<int> summ(n + 1, 0);
	vector<int> ob;
	ob.push_back(0);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			summ[j + 1] = summ[j];
			if (qi[j][i] == 'o') summ[j + 1] = summ[j] + 1;
			else if (qi[j][i] == 'x') ob.push_back(j + 1);
		}
		if (ob.size() == 1)
		{
			for (int k = 0; k < n; ++k)
			{
				qi[k][i] = '.';
			}
		}
		else
		{
			for (int j = ob.back(); j < n; ++j)
			{
				qi[j][i] = '.';
			}
		}
		for (int j = ob.size() - 1; j > 0; --j)
		{
			int box = summ[ob[j]] - summ[ob[j - 1]];
			if (box == 0) continue;
			for (int k = ob[j] - 1; k > ob[j - 1]; --k)
			{
				if (box)
				{
					qi[k - 1][i] = 'o';
					box -= 1;
				}
				else qi[k - 1][i] = '.';
			}
		}
		ob.clear();
		ob.push_back(0);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << qi[i] << endl;
	}
	return 0;
}
