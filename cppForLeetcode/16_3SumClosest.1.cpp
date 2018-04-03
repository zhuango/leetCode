#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum;
        int result;
        int diff;

        int start = 0;
        int middle = 1;
        int end = 2;
        int tempTarget = 0;

        result = target - (nums[start] + nums[middle] + nums[end]);
        while (end < nums.size())
        {
            tempTarget = target - nums[end];
            start = 0;
            middle = end - 1;
            while (start < middle)
            {
                sum = nums[start] + nums[middle];
                diff = tempTarget - sum;
                if (abs(diff) < abs(result))
                {
                    result = diff;
                }
                if (diff > 0)
                {
                    start += 1;
                }
                else
                {
                    middle -= 1;
                }
            }
            end += 1;
        }
        return target - result;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums = {-1, 2, 1, -4};
    so.threeSumClosest(nums, 1);
    return 0;
}