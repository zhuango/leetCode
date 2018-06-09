#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] == newColor) return ;
        if(image[sr][sc] == oldColor)
        {
            image[sr][sc] = newColor;
        }
        else return;
        dfs(image, sr + 1, sc, newColor, oldColor);
        dfs(image, sr - 1, sc, newColor, oldColor);
        dfs(image, sr, sc + 1, newColor, oldColor);
        dfs(image, sr, sc - 1, newColor, oldColor);
    }
};

int main(void)
{
    vector<vector<int>> a= {{0,0,0},{0,1,1}};
    Solution sol;
    for(auto &col : sol.floodFill(a, 1, 1,1))
    {
        for(auto i : col)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}