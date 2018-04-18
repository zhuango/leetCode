#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<pair<int, int>> count;
        if(nums[0] == 0) count.push_back({1, 0});
        else count.push_back({0, 1});
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[0]) count.push_back({count.back.first, count.back.second + 1});
            else count.push_back({count.back.first + 1, count.back.second});
        }
        
    }
};