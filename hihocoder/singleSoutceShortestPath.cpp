#include <iostream>
#include <vector>
#include <list>

using namespace std;
//
//dijkstra's algorithm
//
int main(void)
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<int>> gra(n + 1, vector<int>(n + 1, 0x7fffffff));
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        int distance;
        cin >> u >> v >> distance;
        if(distance < gra[u][v])
        {
            gra[u][v] = distance;
            gra[v][u] = distance;
        }
    }
    vector<int> dist(n + 1, 0x7fffffff);
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    int cur = s;
    dist[s] = 0;
    while(!visited[cur])
    {
        visited[cur] = true;
        for(int i = 1; i <= n; ++i)
        {
            if(gra[cur][i] != 0x7fffffff && dist[i] > dist[cur] + gra[cur][i])
            {
                dist[i] = dist[cur] + gra[cur][i];
                parent[i] = cur;
            }
        }
        cur = s;
        int temp = 0x7fffffff;
        for(int i = 1; i <= n; ++i)
        {
            if(!visited[i] && temp > dist[i])
            {
                temp = dist[i];
                cur = i;
            }
        }
    }
    list<int> path;
    int start = t;
    path.push_front(t);
    while(parent[start] != s)
    {
        path.push_front(parent[start]);
        start = parent[start];
    }
    path.push_front(s);
    for(int i : path)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << dist[t] << endl;

    return 0;
}