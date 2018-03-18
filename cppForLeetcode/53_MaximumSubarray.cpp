#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = 0;
        int max = nums[0];
        for (int elem:nums)
        {
            if (result >= 0)
            {
                result += elem;
            }
            else
            {
                result = elem;
            }
            if (result > max)
            {
                max = result;
            }
        }
        return max;
    }
};