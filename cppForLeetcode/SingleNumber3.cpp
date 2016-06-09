#include "Common.h"

vector<int> singleNumber(vector<int>& nums)
{
    vector<int> result(2, 0);        
    int xo = nums[0];
    for (int i=1; i<nums.size(); i++)
    {
        xo ^= nums[i];
    }

    int bit = xo & ~(xo-1);
    int num1 = 0;
    int num2 = 0;
    
    for_each(nums.begin(), nums.end(), [&num1, &num2, bit](int num) -> void{        
        if ((num & bit) > 0)
        {
            num1 ^= num;
        }
        else
        {
            num2 ^= num;
        }}
    );

    result[0] = num1;
    result[1] = num2;
    return result;
}

int main(void)
{
    int array[] = {1, 1, 2, 2, 3, 4, 5, 3, 5, 7};
    vector<int> input(array, array + 10);
    vector<int> result = singleNumber(input);
    
    for(int i =0; i < 2; ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    //cout << (1 << 2) << endl;
}