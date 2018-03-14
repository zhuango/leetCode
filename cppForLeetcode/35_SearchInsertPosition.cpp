#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = 0;
        for (int a : nums)
        {
            if (a == target || a > target)
            {
                return count;
            }
            count ++;
        }
        return count;
    }
};