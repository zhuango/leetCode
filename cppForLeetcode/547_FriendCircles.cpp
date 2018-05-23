#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> pol = vector<bool>(M.size(), false);
        int count = 0;
        for(int i = 0; i < M.size(); ++i)
        {
            if (dfs(M, pol, i))
            {
                count += 1;
            }
        }
        return count;
    }
    bool dfs(vector<vector<int>> &M, vector<bool> &pol, int row)
    {
        if(pol[row])
        {
            return false;
        }
        pol[row] = true;
        for(int i = 0; i < M.size(); ++i)
        {
            if(M[row][i] == 1 && !pol[i])
            {
                dfs(M, pol, i);
            }
        }
        return true;
    }
};

int main(void)
{
    //vector<vector<int>> input = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    vector<vector<int>> input = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    Solution sol;
    cout << sol.findCircleNum(input) << endl;
}

// [[1,0,0,0],
//  [0,1,1,0],
//  [0,1,1,1],
//  [1,0,1,1]]