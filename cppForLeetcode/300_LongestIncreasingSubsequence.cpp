#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> maxL(nums.size(), 0);
        int result = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            int maxTemp = 0;
            for(int j = 0; j < maxL.size(); ++j)
            {
                if (nums[i] > nums[j] && maxL[j] > maxTemp)
                {
                    maxTemp = maxL[j];
                }
            }
            maxL[i] = maxTemp + 1;
            if(maxL[i] > result)
            {
                result = maxL[i];
            }
        }

        return result;
    }
};

int main(void)
{
    vector<int> s = {3, 4, 5, 6, 7};
    int a = lower_bound(s.begin(), s.end(), 4) - s.begin();
    cout << a << endl;

}