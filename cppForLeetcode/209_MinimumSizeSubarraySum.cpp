#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = nums.size() + 1;
        int length = 0;
        int sum = 0;
        int i=0 , j=0;
        while (i < nums.size())
        {
            sum += nums[i];
            length += 1;
            while (sum >= s)
            {
                sum -= nums[i++];
                length -= 1;
                if (length < result)
                {
                    result = length;
                }
            }

            i ++;
        }
        if (result == nums.size() + 1)
        {
            return 0;
        }
        else
        {
            return result;
        }
    }
};