#include <vector>
#include <iostream>
#include <map>


using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int result = 0;
        int length = grid.size();
        for(int i = 0; i < length - 2; ++i)
        {
            for(int j = 0; j < length - 2; ++j)
            {
                if(checkUni(grid, i, j) && checkSum(grid, i, j))
                {
                    result += 1;
                }
            }
        }
        return result;
    }
    bool checkUni(vector<vector<int>> &grid, int i, int j)
    {
        vector<bool> record(16, false);
        int lowi = i + 2;
        int lowj = j + 2;
        int tempj = j;
        while(i <= lowi)
        {
            j = tempj;
            while(j <= lowj)
            {
                if(!record[grid[i][j]] && grid[i][j] <= 9 && grid[i][j] > 0)
                {
                    record[grid[i][j]] = true;
                }
                else
                {
                    return false;
                }
                j += 1;
            }
            i += 1;
        }
        return true;
    }
    bool checkSum(vector<vector<int>> &grid, int i, int j)
    {
        int sum = grid[i][j + 1] + grid[i][j] + grid[i][j + 2];
        for(int ii = i + 1; ii < i + 3; ++ii)
        {
            int temp =0;
            for(int jj = j; jj < j + 3; ++jj)
            {
                temp += grid[ii][jj];
            }
            if(temp != sum) return false;
        }
        for(int jj = j; jj < j + 3; ++jj)
        {
            int temp = 0;
            for(int ii = i; ii < i + 3; ++ii)
            {
                temp += grid[ii][jj];
            }
            if(temp != sum) return false;
        }
        if(grid[i][j] + grid[i+1][j+1] + grid[i + 2][j + 2] != sum) return false;
        if(grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != sum) return false;
        return true;
    }
};

int main(void)
{
    //vector<vector<int>> input = {{4,3,8,4},{9,5,1,9},{2,7,6,2},{1, 2, 3, 4}};
    vector<vector<int>> input = {{7,0,5},{2,4,6},{3,8,1}};
    Solution sol;
    cout << sol.numMagicSquaresInside(input) << endl;
}