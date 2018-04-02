#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = 0;
        int index = 0;
        int a = 0;
        int maxMuti = 0;
        int max1 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            a = nums[i];
            if (a > max)
            {
                max1 = max;
                max = a;
                index = i;
            }
            else if (a > max1)
            {
                max1 = a;
            }
        }

        return max1 * 2 > max ? -1 : index;
    }
};