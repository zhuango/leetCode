#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results{{}};
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int lastStart = 1;
        int count = 0;
        int prevSize = 0;
        for (int i = 0; i < nums.size();)
        {
            count = 0;
            while(i + count < nums.size() && nums[i + count] == nums[i]) count += 1;

            prevSize = results.size();
            for (int j = 0; j < prevSize; ++j)
            {
                temp = results[j];
                for(int k = 0; k < count; ++k)
                {
                    temp.push_back(nums[i]);
                    results.push_back(temp);
                }
            }
            i += count;
        }
        return results;
    }
};