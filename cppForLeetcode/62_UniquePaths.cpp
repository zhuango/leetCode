#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m, vector<int>(n, 0));
        int column = n;
        int row = m;
        for (int i = 0; i < row; ++i)
        {
            table[i][n-1] = 1;
        }
        for (int i = column - 2; i >= 0; --i)
        {
            for(int j = row - 1; j >= 0; --j)
            {
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