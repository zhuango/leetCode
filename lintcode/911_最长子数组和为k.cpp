#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        vector<int> summ(nums.size() + 1);
        summ[0] = 0;
        unordered_map<int, int> mapping;
        for(int i = 1; i <= nums.size(); ++i)
        {
            summ[i] = summ[i-1] + nums[i-1];
            mapping[summ[i]] = i;
        }
        int length = 0;
        for(int i = 0; i < summ.size(); ++i)
        {
            int target = k + summ[i];
            if(mapping.count(target) != 0)
            {
                if(mapping[target]-i > length)
                length = mapping[target] - i;
            }
        }
        return length;
    }
};