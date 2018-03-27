#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> rowMax;
        vector<int> colMax;
        int mm = 0;
        for(int i = 0; i < row; ++i)
        {
            mm = 0;
            for(int j = 0; j < col; ++j)
            {
                if (grid[i][j] > mm)
                {
                    mm = grid[i][j];
                }
            }
            rowMax.push_back(mm);
        }

        for(int i = 0; i < col; ++i)
        {
            mm = 0;
            for(int j = 0; j < row; ++j)
            {
                if (grid[j][i] > mm)
                {
                    mm = grid[j][i];
                }
            }
            colMax.push_back(mm);
        }
        int results = 0;
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                mm = min(rowMax[i], colMax[j]) - grid[i][j];
                results += mm > 0 ? mm : 0;
            }
        }
        return results;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> input = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    cout << sol.maxIncreaseKeepingSkyline(input) << endl;
}