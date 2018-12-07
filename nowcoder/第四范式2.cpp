#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &neig, vector<int> &targ, int curNode, int color)
{
    for(int nei : neig[curNode])
    {
        if(targ[nei] == color) return false;
    }
    targ[curNode] = color;
    int newColor = -1;
    if(color == -1) newColor = 1;
    for(int nei : neig[curNode])
    {
        bool result = false;
        if(targ[nei] == 0)
        {
            result = dfs(neig, targ, nei, newColor);
            if(!result) return false;
        }
    }
    return true;
}
int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<int> targ(n+1, 0);
    vector<vector<int>> neig(n + 1);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        neig[u].push_back(v);
        neig[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
    {
        bool result = false;
        if(targ[i] == 0)
        {
            result = dfs(neig, targ, i, -1);
            if(!result) 
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}