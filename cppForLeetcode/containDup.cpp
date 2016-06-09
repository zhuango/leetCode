#include "Common.h"

bool containsDuplicate(vector<int>& nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[i] == nums[j]) return true;
        }
    }
    return false;
}

bool containsDuplicate_opti(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] == nums[i - 1]) return true;
    }
    return false;
}
#include <set>
bool containsDuplicate_smart(vector<int>& nums)
{
    return nums.size() > set<int>(nums.begin(), nums.end()).size();  
}

int main(void)
{
    vector<int> inputs = {1,2 ,3 ,4,5, 5, 6, 7, 8, 9};
    cout << containsDuplicate(inputs) << endl;
    vector<int> inputs2 = {1,2 ,3 ,4,5, 10, 6, 7, 8, 9};
    cout << containsDuplicate(inputs2) << endl;
}
