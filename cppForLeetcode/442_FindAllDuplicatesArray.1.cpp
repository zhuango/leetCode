#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> results;
        int temp = 0;
        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
            else ++i;
        }
        for(i = 0; i < nums.size(); ++i)
        {
            if (i + 1 != nums[i]) results.push_back(nums[i]);
        }
        return results;
    }
};