#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int length = 0.0;
        for_each(nums.begin(), nums.end(), [&length](int i) {length += i;});
        if(length % 4) return false;
        sort(nums.begin(), nums.end(), [](int a, int b){ return a > b; });
        vector<int> target(4, length / 4);
        return dfs(nums, 0, target);
    }
    bool dfs(vector<int>&nums, int index, vector<int> &target)
    {
        if(index == nums.size())
        {
            return true;
        }
        for(int i = 0; i < 4; ++i)
        {
            if(target[i] >= nums[index])
            {
                target[i] -= nums[index];
                if (dfs(nums, index + 1, target)) return true;
                target[i] += nums[index];
            }
        }
        return false;
    }
};

int main(void)
{
    vector<int> array = {234, 2, 1,2, 54, 2, 5};
    sort(array.begin(), array.end(), [](int a, int b){ return a > b; });
    for(int i : array)
    {
        cout << i << endl;
    }
}