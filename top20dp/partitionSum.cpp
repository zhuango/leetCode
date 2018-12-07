#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a non-empty array only positive integers
     * @return: true if can partition or false
     */
    bool canPartition(vector<int> &nums) {
        // write your code here
        int sum = 0;
        for(int i : nums) sum += i;
        if(sum % 2 != 0) return false;

        vector<vector<int>> dp(sum / 2 + 1, vector<int>(nums.size(), 0));
        for(int i = 1; i < sum / 2 + 1; ++i)
        {
            if(nums[0] > i)
            {
                dp[i][0] = 0;
            }
            else dp[i][0] = nums[0];
            cout << "DDDDDDDDDDDD" << endl;
            if(dp[i][0] == sum/2) return true;
            for(int j = 1; j < nums.size(); ++j)
            {
                if(nums[j] > i)
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-nums[j]][j-1] + nums[j]);
                    if(dp[i][j] == sum / 2) return true;
                }
            }
        }
        return false;
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {2, 5, 11, 5};
    cout << sol.canPartition(input) << endl;
}