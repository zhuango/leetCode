#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max = 1;
        int result = 1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] < nums[i+1])
            {
                result += 1;
                if (result > max)
                {
                    max = result;
                }
            }
            else
            {
                result = 1;
            }
        }
        return max;
    }
};