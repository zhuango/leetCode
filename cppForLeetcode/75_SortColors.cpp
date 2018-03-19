#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;
        int temp;
        int i = 0;
        while (i < nums.size() && nums[i] == 0)
        {
            i++;
        }
        red = i;
        while (i <= blue)
        {
            if (nums[i] == 0)
            {
                temp = nums[i];
                nums[i] = nums[red];
                nums[red] = temp;
                red += 1;
            }
            else if (nums[i] == 2)
            {
                temp = nums[i];
                nums[i] = nums[blue];
                nums[blue] = temp;
                blue -= 1;
            }
            else
            {
                ++i;
            }
        }
    }
};