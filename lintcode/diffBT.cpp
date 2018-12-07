#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};