#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) return 0.0;
        double result = 0.0;
        double temp = 0.0;
        for (int i = 0; i < k; ++i)
        {
            temp += nums[i];
        }
        result = temp;
        for (int i = k; i < nums.size(); ++i)
        {
            temp += nums[i] - nums[i-k];
            if (temp > result)
            {
                result = temp;
            }
        }
        return result / k;
    }
};