#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        results = 0.0;
        vector<int> ss(A.size(), 0);
        int length = A.size();
        ss[0] = A[0];
        for (int i = 1; i < length; ++i)
        {
            ss[i] = ss[i - 1] + A[i];
        }
        vector<vector<double>> dp(length, vector<double>(K + 1, 0));
        return backTrack(A, ss, K, 0, dp);
    }
    double backTrack(vector<int> &A, vector<int> &ss, int K, int index, vector<vector<double>> &dp)
    {
        if (K == 1)
        {
            return ((ss[A.size() - 1] - ss[index] + A[index]) * 1.0 / (A.size() - index));
        }
        if (dp[index][K] != 0) return dp[index][K];
        int rest = A.size() - index;
        double curSum = 0;
        for(int i = 0; i < rest - K + 1; ++i)
        {
            curSum = max( curSum, ((ss[i + index] - ss[index] + A[index])) * 1.0 / (i + 1) + backTrack(A, ss, K - 1, i + index + 1, dp) );
        }
        dp[index][K] = curSum;
        return curSum;
    }

    private:
    double results = 0.0;
};

int main(void)
{
    Solution sol;
    vector<int> input = {4663,3020,7789,1627,9668,1356,4207,1133,8765,4649,205,6455,8864,3554,3916,5925,3995,4540,3487,5444,8259,8802,6777,7306,989,4958,2921,8155,4922,2469,6923,776,9777,1796,708,786,3158,7369,8715,2136,2510,3739,6411,7996,6211,8282,4805,236,1489,7698};
    int k = 27;
    cout << sol.largestSumOfAverages(input, k) << endl;
}