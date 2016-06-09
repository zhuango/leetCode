#include "Common.h"

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> result(nums.size(), 0);
    int sum = 1;
    unsigned int j = 0;
    for(; j != nums.size() && (nums[j]) != 0; ++j)
    {
        sum *= nums[j];
    }
    unsigned int zerospos = j;
    for(;j < nums.size(); ++j)
    {
        nums[zerospos] = 1;
        sum *= nums[j];
    }
    for(unsigned int iter = 0; iter < nums.size() && zerospos >= nums.size(); ++iter)
    {
        result[iter] = sum / nums[iter];
    }
    for(unsigned int iter = zerospos; iter < nums.size(); ++iter)
    {
        result[iter] = 0; 
        result[zerospos] = sum;
    }
    return result;
}

vector<int> producrExceptSelf_smart(vector<int> &nums)
{
    int n = nums.size();
    vector<int> a(n, 0);
    for (int i = 0, left = 1; i < n; i++) {
        a[i] = left;
        left *= nums[i];
    }
    for (int i = n - 1, right = 1; i >= 0; i--) {
        a[i] *= right;
        right *= nums[i];
    }
    return a;
}
//   1 2 3 4 5 6
//   -----------
// 1|  1 1 1 1 1
// 2|2   2 2 2 2
// 3|3 3   3 3 3
// 4|4 4 4   4 4
// 5|5 5 5 5   5
// 6|6 6 6 6 6
//(horizontal axis is nums array, vertical axis is multiplied times)
int main(void)
{
    int array[] = {1, 2, 23, 0, 0};
    vector<int> inputs(array, array + 5);
    vector<int> output = producrExceptSelf_smart(inputs);
    for(auto iter = output.begin(); iter != output.end(); ++iter)
    {
        cout << (*iter) << " ";
    }
    cout << endl;
}
