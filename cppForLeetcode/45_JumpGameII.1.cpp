#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0;
        int farest = 0;
        int step = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (i + nums[i] > farest) farest = i + nums[i];
            if (i == curEnd)
            {
                step ++;
                curEnd = farest;
            }
        }
        return step;
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {2,1,3,1,4};
    cout << sol.jump(input) << endl;
}