#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        int edge = 0;
        for(int i = 0; i < row; ++i)
        {
            if(grid[i][0]==1) count ++;
            if(grid[i][col-1] == 1) count ++;
        }
        for(int j = 0; j < col; ++j)
        {
            if (grid[0][j] == 1) count ++;
            if (grid[row -1][j] == 1) count ++;
        }
        for(int i = 1; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
                if(grid[i][j] != grid[i-1][j]) count ++;
        }
        for(int j = 1; j < col; ++j)
        {
            for(int i = 0; i < row; ++i)
                if(grid[i][j] != grid[i][j-1]) count ++;
        }
        return count;
    }
};