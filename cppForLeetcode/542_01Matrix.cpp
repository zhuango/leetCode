#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

class PosL
{
    public:
    PosL(int r, int c, int d):row(r), col(c), dis(d){}
    int row;
    int col;
    int dis;
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<vector<int>>();
        int m = matrix.size();
        int n = matrix[0].size();
        int maxmn = m + n;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    continue;
                }
                int val = maxmn;
                if(i > 0) val = min(val, matrix[i-1][j] + 1);
                if(j > 0) val = min(val, matrix[i][j-1] + 1);
                matrix[i][j] = val;
            }
        }
        for(int i = m - 1; i >= 0; --i)
        {
            for(int j = n - 1; j >= 0; --j)
            {
                if(matrix[i][j] == 0)
                {
                    continue;
                }
                int val = matrix[i][j];
                if(i < m - 1) val = min(val, matrix[i+1][j] + 1);
                if(j < n - 1) val = min(val, matrix[i][j+1] + 1);
                matrix[i][j] = val;
            }
        }


        return matrix;
    }
};

int main(void)
{
    vector<vector<int>> matrix = {{0,0,0},{0,1,0},{0,0,0}};
    //vector<vector<int>> matrix = {{0,0,0},{0,1,0},{1,1,1}};
    //vector<vector<int>> matrix = {{0,1,1},{0,1,1},{0,1,1}};
    //vector<vector<int>> matrix = {{0,1,1},{1,1,1},{1,1,1}};
    Solution sol;
    vector<vector<int>> results = sol.updateMatrix(matrix);
    for(auto &v : results)
    {
        for(int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}