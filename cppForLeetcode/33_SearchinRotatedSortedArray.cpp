#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int spliter = findWrongOrderPos(nums);
        int index = find(nums, 0, spliter - 1, target);
        if (index != -1) return index;
        index = find(nums, spliter, nums.size() - 1, target);
        if (index != -1) return index;
        return index;
    }
    int findWrongOrderPos(vector<int> &nums)
    {
        int index = 0;
        while (index < nums.size() - 1)
        {
            if (nums[index] > nums[index + 1])
            {
                return index + 1;
            }
            index += 1;
        }
        return index;
    }
    int find(vector<int> &nums, int start, int end, int target)
    {
        int middle = 0;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] == target)
            {
                return middle;
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
        return -1;
    }
};