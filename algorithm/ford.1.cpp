#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> weights(map);
    int i,j; /* dimension counters */
    int k; /* intermediate vertex counter */
    int through_k; /* distance through vertex k */
    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++) {
                through_k = weights[i][k]+ weights[k][j];
                if (through_k < weights[i][j])
                    weights[i][j] = through_k;
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