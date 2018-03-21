#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int prev = -2147483648;
        int last;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums.size() - 1) last = nums[nums.size() - 1] - 1;
            else last = nums[i + 1];
            if (nums[i] > prev && nums[i] > last)
            {
                return i;
            }
        }
        return 0;
    }
};