#include <iostream>
#include <vector>

using namespace std;

// vector<int> getPath(vector<vector<int>> &path, int s, int t)
// {
    
// }

int main(void)
{
    int n, m;
    cin >> n >> m;
    int maxlenght = 200000;
    vector<vector<int>> gra(n + 1, vector<int>(n + 1, maxlenght));
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        int distance = 0;
        cin >> u >> v >> distance;
        if(gra[u][v] > distance)
        {
            gra[u][v] = distance;
            gra[v][u] = distance;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        gra[i][i] = 0;
    }
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dist(gra);
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(dist[i][j] < maxlenght)
                cout << dist[i][j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}