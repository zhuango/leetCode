#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int k;
    int d;
    vector<int> power;
    cin >> n;
    int temp = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> temp;
        power.push_back(temp);
    }
    cin >> k >> d;
    vector<vector<long long>> dpmax(n, vector<long long>(k + 1, 0));
    vector<vector<long long>> dpmin(n, vector<long long>(k + 1, 0));
    for(int i = 0; i < n; ++i)
    {
        dpmax[i][1] = power[i];
        dpmin[i][1] = power[i];
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 2; j <= k; ++j)
        {
            for(int m = max(0, i - d); m <= i - 1; ++m)
            {
                dpmax[i][j] = max(dpmax[i][j], max(dpmax[m][j-1] * power[i], dpmin[m][j-1] * power[i]));
                dpmin[i][j] = min(dpmin[i][j], min(dpmax[m][j-1] * power[i], dpmin[m][j-1] * power[i]));
            }
        }
    }
    long long result = dpmax[k-1][k];
    for(int i = k; i < n; ++i)
    {
        result = max(result, dpmax[i][k]);
    }
    cout << result << endl;
    return 0;
}