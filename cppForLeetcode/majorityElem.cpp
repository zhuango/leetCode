#include "Common.h"
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = nums[0];
    int times= 1;
    int curmax = 0;
    for(int i = 1; i < nums.size();++i)
    {
        if(nums[i] != nums[i - 1])
        {
            times = 1;
        }
        else
        {
            times ++;
            if(times > curmax)
            {
                curmax = times;
                result = nums[i];
            }
        }
    }

    return result;
}

int majorityElement_Bril(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int majorityElement_smart(vector<int>& nums) {
        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;

        }
        return major;
}
int main(void)
{
    vector<int> input = {2, 2, 2, 3,1,1, 1, 1, 1, 1};
    cout << majorityElement(input) << endl;
}