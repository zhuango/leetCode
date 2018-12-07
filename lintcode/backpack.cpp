#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<vector<int>> dp(m + 1, vector<int>(A.size(), 0));
        for(int i = 0; i < A.size(); ++i)
        {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= m; ++i)
        {
            if(A[0] <= i)
            {
                dp[i][0] = A[0];
            }
            else dp[i][0] = 0;
            for(int j = 1; j < A.size(); ++j)
            {
                if(A[j] > i)
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-A[j]][j-1] + A[j], dp[i][j-1]);
                }
            }
        }
        return dp[m][A.size() -1];
    }
};