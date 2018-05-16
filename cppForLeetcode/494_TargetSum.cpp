#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, S, 0);
        return count;
    }
    void dfs(vector<int> &nums, int S, int index)
    {
        if(S == 0 && index == nums.size())
        {
            count += 1;
            return ;
        }
        if(index == nums.size()) return ;
        dfs(nums, S-nums[index], index + 1);
        dfs(nums, S+nums[index], index + 1);
    }

    private:
    int count = 0;
};