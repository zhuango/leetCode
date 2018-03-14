#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int middle = 0;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] < target)
            {
                start = middle + 1;
            }
            else if (nums[middle] > target)
            {
                end = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return start;
    }
};