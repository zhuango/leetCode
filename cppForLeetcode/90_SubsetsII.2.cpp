#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results{};
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backTrack(results, nums, temp, 0);
        return results;
    }
    void backTrack(vector<vector<int>> &results, vector<int> &nums, vector<int> temp, int index)
    {
        results.push_back(temp);
        for(int i = index; i < nums.size(); ++i)
        {
            if (i == index || nums[i] != nums[i - 1])
            {
                temp.push_back(nums[i]);
                backTrack(results, nums, temp, i + 1);
                temp.pop_back();
            }
        }
    }
};