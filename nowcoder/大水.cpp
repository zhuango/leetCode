#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<bool>> &visi, vector<vector<int>> &land, int i, int j, int h)
{
    if(i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || visi[i][j] || land[i][j] > h)
    {
        return;
    }
    visi[i][j] = true;
    dfs(visi, land, i + 1, j, h);
    dfs(visi, land, i - 1, j, h);
    dfs(visi, land, i, j + 1, h);
    dfs(visi, land, i, j - 1, h);
}

int main(void)
{
    int m, n, h;
    cin >> m >> n >> h;
    vector<vector<int>> land(m, vector<int>(n, 0));
    vector<vector<bool>> visi(m, vector<bool>(n, false));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> land[i][j];
        }
    }
    for(int i = 0; i < m; ++i)
    {
        if(!visi[i][0] && land[i][0] <= h)
        {
            dfs(visi, land, i, 0, h);
        }
        if(!visi[i][n - 1] && land[i][n -1] <= h)
        {
            dfs(visi, land, i, n-1, h);
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(!visi[0][i] && land[0][i] <= h)
        {
            dfs(visi, land, 0, i, h);
        }
        if(!visi[m - 1][i] && land[m - 1][i] <= h)
        {
            dfs(visi, land, m - 1, i, h);
        }
    }
    int count = 0;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!visi[i][j]) count += 1;
        }
    }
    cout << count << endl;

    return 0;
}