#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> table(grid.size(), vector<bool>(grid[0].size(), true));
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if (table[i][j] && grid[i][j])
                {
                    count = 0;
                    backTrack(grid, table, i, j);
                }
                if (count > result)
                {
                    result = count;
                }
            }
        }
        return result;
    }
    void backTrack(vector<vector<int>> & grid, vector<vector<bool>> &table, int row, int col)
    {
        if (table[row][col] && grid[row][col])
        {
            count += 1;
            table[row][col] = false;
        }
        else
        {
            return ;
        }
        if (row + 1 < m)
        {
            backTrack(grid, table, row + 1, col);
        }
        if (row - 1 >= 0)
        {
            backTrack(grid, table, row - 1, col);
        }
        if (col + 1 < n)
        {
            backTrack(grid, table, row, col + 1);
        }
        if (col - 1 >= 0)
        {
            backTrack(grid, table, row, col - 1);
        }
    }
    private:
    int count = 0;
    int m = 0;
    int n = 0;
};