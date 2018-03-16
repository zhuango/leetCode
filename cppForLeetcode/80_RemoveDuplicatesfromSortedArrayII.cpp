#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int repeat = 1;
        int curIndex = 0;
        int index = 1;
        if (nums.empty()) return 0;
        while (index < nums.size())
        {
            if (nums[index] != nums[curIndex])
            {
                curIndex += 1;
                nums[curIndex] = nums[index];
                repeat = 1;
            }
            else if (repeat < 2)
            {
                curIndex += 1;
                nums[curIndex] = nums[index];
                repeat += 1;
            }
            index += 1;
        }
        return curIndex + 1;
    }
};