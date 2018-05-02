#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> results;
        if(matrix.empty()) return results;
        vector<vector<short>> pacificTag(matrix.size(), vector<short>(matrix[0].size(), -1));
        vector<vector<short>> atlanticTag(matrix.size(), vector<short>(matrix[0].size(), -1));
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                auto pair = canReachBothOcean(matrix, i, j, pacificTag, atlanticTag, visited);
                if (pair.first && pair.second) results.push_back({i, j});
                if (!pair.first) pacificTag[i][j] = 0;
                if (!pair.second) atlanticTag[i][j] = 0;
            }
        }
        return results;
    }
    pair<bool, bool> canReachBothOcean(vector<vector<int>> &matrix, int row, int col, vector<vector<short>> &pacificTag, vector<vector<short>> &atlanticTag, vector<vector<bool>> &visited)
    {
        bool pacific = false;
        bool atlantic = false;
        
        if(row <= 0 || col <= 0)
        {
            pacific = true;
        }
        if(row >= matrix.size()-1 || col >= matrix[0].size()-1)
        {
            atlantic = true;
        }
        if (pacific && atlantic)
        {
            pacificTag[row][col] = 1;
            atlanticTag[row][col] = 1;
            return {true, true};
        }
        
        if(visited[row][col] || (pacificTag[row][col] != -1 && atlanticTag[row][col] != -1)) return {pacificTag[row][col] == 1, atlanticTag[row][col] == 1};
        if(pacificTag[row][col] == 1) pacific = true;
        if(atlanticTag[row][col] == 1) atlantic = true;
        visited[row][col] = true;

        if(row-1 >= 0 && matrix[row][col] >= matrix[row-1][col])
        {
            auto bottom = canReachBothOcean(matrix, row - 1, col, pacificTag, atlanticTag, visited);
            if(bottom.first) pacific = true;
            if(bottom.second) atlantic = true;
        }
        if(col-1 >= 0 && matrix[row][col] >= matrix[row][col-1])
        {
            auto left = canReachBothOcean(matrix, row, col - 1, pacificTag, atlanticTag, visited);
            if(left.first) pacific = true;
            if(left.second) atlantic = true;
        }
        
        if(row+1 < matrix.size() && matrix[row][col] >= matrix[row+1][col])
        {
            auto top = canReachBothOcean(matrix, row + 1, col, pacificTag, atlanticTag, visited);
            if(top.first) pacific = true;
            if(top.second) atlantic = true;
        }

        if(col+1 < matrix[0].size() && matrix[row][col] >= matrix[row][col+1])
        {
            auto right = canReachBothOcean(matrix, row, col + 1, pacificTag, atlanticTag, visited);
            if(right.first) pacific = true;
            if(right.second) atlantic = true;
        }
        
        visited[row][col] = false;
        if(pacific) pacificTag[row][col] = 1;
        if(atlantic)atlanticTag[row][col] = 1;
        return {pacific, atlantic};
    }
};

int main(void)
{
    vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution sol;
    for(auto &pair : sol.pacificAtlantic(matrix))
    {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}