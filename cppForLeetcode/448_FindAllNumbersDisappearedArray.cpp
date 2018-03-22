#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> results;
        int i = 0;
        int temp = 0;
        while(i < nums.size())
        {
            temp = abs(nums[i]) - 1;
            nums[i] = nums[i] > 0 ? -nums[i] : nums[i];
            i += 1;
        }
        i = 0;
        while (i < nums.size())
        {
            if (nums[i] > 0) results.push_back(i+1);
        }
        return results;
    }
};