#include "Common.h"

int singleNumber(vector<int>& nums)
{
    for(vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); ++iter)
    {
        nums[0] ^= (*iter);
    }
    return nums[0];
}

int main(void)
{
    int array[] = {1, 2, 3, 4, 3, 2, 1, 5, 5};
    vector<int> input(array, array + 9);
    cout << singleNumber(input) << endl;
}