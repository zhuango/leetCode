#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    while(cin >> n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 3;
        dp[2] = 9;
        for(int i = 3; i <= n; ++i)
        {
            dp[i] = 2 * dp[i-1] + dp[i-2];
        }
        cout << dp[n] << endl;
    }
}