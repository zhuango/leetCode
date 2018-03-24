#include <vector>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxLength = 0;
        int curLength = 0;
        int tempIndex = 0;
        vector<bool> table(nums.size(), true);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                continue;
            }
            curLength = 1;
            tempIndex = nums[i];
            table[i] = false;
            while(table[tempIndex])
            {
                table[tempIndex] = false;
                tempIndex = nums[tempIndex];
                curLength += 1;
            }
            if (curLength > maxLength) maxLength = curLength;
        }
        return maxLength;
    }
};