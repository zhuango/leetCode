#include <iostream>
#include <vector>

using namespace std;

int inline calmatrixSum(vector<vector<int>> &sum, int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}
bool sat(vector<vector<int>> & sum, int k)
{
    int n = sum.size()-1;
    int m = sum[0].size()-1;
    for(int x1 = 1; x1 <= n-3; ++x1)
    {
        for(int x2 = x1 + 1; x2 <= n - 2; ++x2)
        {
            for(int x3 = x2 + 1; x3 <= n - 1; ++x3)
            {
                int cnt = 0;
                int rec = 0;
                for(int y = 1; y <= m; ++y)
                {
                    if(calmatrixSum(sum, 0, rec, x1, y) >= k 
                    && calmatrixSum(sum, x1, rec, x2, y) >= k
                    && calmatrixSum(sum, x2, rec, x3, y) >= k
                    && calmatrixSum(sum, x3, rec, n, y) >= k)
                    {
                        cnt += 1;
                        rec = y;
                    }
                }
                if(cnt >= 4)
                {
                    return true;    
                }
            }
        }
    }
    return false;
}

int main(void)
{
    int m,n;
    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j)
        {
            field[i][j] = s[j] - '0';
        }
    }
    vector<vector<int>> ss(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            ss[i][j] = ss[i][j-1] + ss[i-1][j] - ss[i-1][j-1] + field[i-1][j-1];
        }
    }
    int result = 0;
    int l = 0, r = ss[n][m];
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(sat(ss, mid))
        {
            l = mid + 1;
            result = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << result << endl;
}