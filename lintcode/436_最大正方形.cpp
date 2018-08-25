#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param matrix: a matrix of 0 and 1
	* @return: an integer
	*/
	int maxSquare(vector<vector<int>> &matrix) {
		// write your code here
		vector<vector<int>> summ(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		for (int i = 1; i <= matrix.size(); ++i)
		{
			for (int j = 1; j <= matrix[0].size(); ++j)
			{
				summ[i][j] = summ[i - 1][j] + summ[i][j - 1] - summ[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
		if(summ.back().back() == 0) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int maxS = min(m, n);
		for (int k = maxS; k >= 2; --k)
		{
			int ks = k * k;
			for (int i = 0; i <= m - k; ++i)
			{
				for (int j = 0; j <= n - k; ++j)
				{
					if (summ[i + k][j + k] - summ[i][j + k] - summ[i + k][j] + summ[i][j] == ks)
					{
						return k*k;
					}
				}
			}
		}
		return 1;
	}
};