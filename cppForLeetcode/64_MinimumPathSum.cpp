#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        int row = m;
        int column = n;

        for (int i = row - 1; i >= 0; --i)
        {
            if (i + 1 < row)
            {
                table[i][n-1] += grid[i+1][n-1] + table[i+1][n-1];
            }
            else
            {
                table[i][n-1] = grid[i][n-1];
            }
        }
        for (int i = column - 2; i >= 0; --i)
        {
            for (int j = row - 1; j >= 0; --j)
            {
                if (i + 1 < column && j + 1 < row)
                {
                    table[j][i] = grid[j][i] + (table[j + 1][i] < table[j][i + 1] ? table[j + 1][i]:table[j][i + 1]);
                }
                else if (j + 1 < row)
                {
                    table[j][i] = grid[j][i] + table[j + 1][i];
                }
                else
                {
                    table[j][i] = grid[j][i] + table[j][i + 1];
                }
            }
        }
        return table[0][0];
    }
};