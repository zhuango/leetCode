#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> results;
        int temp = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            temp = abs(nums[i]) - 1;
            if (nums[temp] < 0)
            {
                results.push_back(temp + 1);
            }
            else
            {
                nums[temp] = -nums[temp];
            }
        }
        return results;
    }
};