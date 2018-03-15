#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        int column = n;
        int row = m;
        for (int i = row - 1; i >= 0; --i)
        {
            if (obstacleGrid[i][n-1] == 1)
            {
                continue;
            }
            if (i + 1 < row)
            {
                table[i][n-1] = table[i+1][n-1];
            }
            else
            {
                table[i][n-1] = 1;
            }
        }
        for (int i = column - 2; i >= 0; --i)
        {
            for(int j = row - 1; j >= 0; --j)
            {
                if (obstacleGrid[j][i] == 1)
                {
                    continue;
                }
                if (j + 1 < row)
                {
                    table[j][i] += table[j + 1][i];
                }
                if (i + 1 < column)
                {
                    table[j][i] += table[j][i + 1];
                }
            }
        }
        return table[0][0];
    }
};
