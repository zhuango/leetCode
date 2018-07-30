#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void shortest(vector<vector<int>> &map, int i, int j, int step, int distance, int &curmin)
{
    if(step == 1)
    {
        distance += map[i][j];
        if(distance < curmin)
        {
            curmin = distance;
        }
        return;
    }
    for(int k = 0; k < map.size(); ++k)
    {
        cout << "DDDDDDDDDD" << i << " " << k << endl;
        if(k == i) continue;
        if(step == 2 && k == j) continue;
        distance += map[i][k];
        shortest(map, k, j, step-1, distance, curmin);
        distance -= map[i][k];
    }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    cin >> n >> n;
    vector<vector<int>> map;
    for(int i = 0; i < n; ++i)
    {
        vector<int> singlemap;
        for(int j = 0; j < n; ++j)
        {
            int temp;
            cin >> temp;
            singlemap.push_back(temp);
        }
        map.push_back(singlemap);
    }
    vector<vector<int>> weights(n, vector<int> (n, 0));
    int k; 
    int through_k;
    for (k=0; k<n; k++)
    {
        through_k = 0x7fffffff;
        int i = k;
        for(; i < n; ++i)
        {
            shortest(map, k, i, m, 0, through_k);
            weights[k][i] = through_k;
            weights[i][k] = through_k;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << weights[i][j] << " ";
        }
        cout << endl;
    }
}