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
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> rec(m, vector<int>(n, 0));
		int result = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(matrix[i][j] == 1)
				{
					if (i == 0 || j == 0)
					{
						rec[i][j] = 1;
					}
					else
					{
						rec[i][j] = min(rec[i - 1][j], min(rec[i - 1][j - 1], rec[i][j - 1])) + 1;
					}
					if(rec[i][j] > result)
						result = rec[i][j];
				}
				else
					rec[i][j] = 0;
			}
		}
		return result * result;
	}
};