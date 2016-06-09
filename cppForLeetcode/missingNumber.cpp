#include "Common.h"
#include <bitset>
int missingNumber(vector<int>& nums) 
{
    vector<bool> table(nums.size() +1 , false);
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
    {
        table[(*iter)] = true;
    }
    for(int i = 0; i < table.size(); ++i)
    {
        if(!table[i]) return i;
    }
}
int missingNumber_smart(vector<int> &nums)
{
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
        sum = sum - nums[i] + i;

    return sum + nums.size();
}
int main(void)
{
    vector<int> array = {0, 1, 2, 3, 4, 5, 6, 8, 9};
    cout << missingNumber_smart(array) << endl;
}