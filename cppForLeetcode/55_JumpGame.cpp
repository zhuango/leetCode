#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int avaPos = int(nums.size() - 1);
        int index = nums.size() - 2;
        int end = nums.size() - 1;
        while (index >= 0)
        {
            if (nums[index] >= avaPos - index)
            {
                avaPos = index;
            }
            index -= 1;
        }
        if (avaPos == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(void)
{
    Solution sol;
    vector<int> input {1, 0, 2};
    cout << sol.canJump(input) << endl;
}