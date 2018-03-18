#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums);
        if (nums[pivot] < nums[0])
        {
            return nums[pivot];
        }
        else
        {
            return nums[0];
        }
    }
    int findPivot(vector<int> & nums)
    {
        int i = 1;
        while (i < nums.size())
        {
            if (nums[i] < nums[i - 1])
            {
                return i;
            }
            i += 1;
        }
        return 0;
    }
};