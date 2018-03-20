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
        while(start <= end)
        {
            middle = start + (end - start) / 2;
            if (nums[middle] == target)
            {
                index = middle - 1;
                while(index >= 0 && nums[index] == target)
                {
                    index -= 1;
                }
                results[0] = index + 1;
                index = middle + 1;
                while(index < nums.size() && nums[index] == target)
                {
                    index += 1;
                }
                results[1] = index - 1;
                break;
            }
            if (nums[middle] < target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        return results;
    }
};