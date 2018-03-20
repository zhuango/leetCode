#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> results(2, -1);
        int start = 0;
        int end = nums.size() - 1;
        int middle = 0;
        int index = 0;
        while(start < end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] < target) start = middle + 1;
            else end = middle;
        }
        if (nums[start] != target) return results;
        results[0] = start;

        end = nums.size() - 1;
        while(start < end)
        {
            middle = start + (end - start) / 2 + 1;
            if (nums[middle] > target) end = middle - 1;
            else start = middle;
        }
        results[1] = end;
        
        return results;
    }
};