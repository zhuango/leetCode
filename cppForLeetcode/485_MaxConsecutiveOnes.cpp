#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int cur = 0;
        for(int a: nums)
        {
            if (a) cur+=1;
            else
            {
                if (cur > max) max = cur;
                cur = 0;
            }
        }
        if (cur > max) max = cur;
        return max;
    }
};