#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        double results = 0.0;
        int length = A.size();
        vector<double> sum(length, 0.0);
        sum[0] = A[0];
        for (int i = 0; i < length; ++i)
        {
            sum[i] = sum[i - 1] + A[i];
        }
        vector<vector<double>> dp(length, vector<double>(K + 1, 0));
        for(int i = 1; i <= K; ++i)
        {
            for (int j = i - 1; j < length; ++j)
            {
                if (i == 1) dp[j][i] = (sum[j] / (j + 1));
                else
                {
                    for(int k = i - 2; k < j; ++k)
                    {
                        dp[j][i] = max(dp[j][i], dp[k][i-1] + (sum[j] - sum[k]) / (j - k));
                    }
                }
            }
        }
        return dp[length - 1][K];
    }
    private:
};

int main(void)
{
    Solution sol;
    vector<int> input = {4663,3020,7789,1627,9668,1356,4207,1133,8765,4649,205,6455,8864,3554,3916,5925,3995,4540,3487,5444,8259,8802,6777,7306,989,4958,2921,8155,4922,2469,6923,776,9777,1796,708,786,3158,7369,8715,2136,2510,3739,6411,7996,6211,8282,4805,236,1489,7698};
    int k = 27;
    cout << sol.largestSumOfAverages(input, k) << endl;
}