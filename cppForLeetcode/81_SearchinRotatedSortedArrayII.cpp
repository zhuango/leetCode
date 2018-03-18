#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int spliter = findWrongOrderPos(nums);
        return find(nums, 0, spliter - 1, target) || find(nums, spliter, nums.size() - 1, target);
    }
    int findWrongOrderPos(vector<int> &nums)
    {
        int index = 0;
        while (index < nums.size() - 1)
        {
            if (nums[index] > nums[index + 1])
            {
            }
            index += 1;
        }
        return index;
    }
    bool find(vector<int> &nums, int start, int end, int target)
    {
        int middle = 0;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] == target)
            {
                return true;
            }
            if(nums[middle] < target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        return false;
    }
};