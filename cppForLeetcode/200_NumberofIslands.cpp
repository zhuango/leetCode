#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<bool>> marks(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if (marks[i][j] || grid[i][j] == '0') continue;
                else count += 1;
                dfs(marks, grid, i, j);
            }
        }
        return count;
    }
    void dfs(vector<vector<bool>> &marks, vector<vector<char>> &grid, int row, int col)
    {
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0) return ;
        if (marks[row][col] || grid[row][col] == '0')
        {
            marks[row][col] = true;
            return ;
        }
        marks[row][col] = true;
        dfs(marks, grid, row, col + 1);
        dfs(marks, grid, row, col - 1);
        dfs(marks, grid, row + 1, col);
        dfs(marks, grid, row - 1, col);
    }
};