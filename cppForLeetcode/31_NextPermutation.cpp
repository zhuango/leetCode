#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size();
        for (i = nums.size() - 1; i > 0; --i)
        {
            if(nums[i] > nums[i-1])
            break;
        }
        cout << i << endl;
        if(i==0)
        {
            reverse(nums, 0, nums.size() - 1);
        }
        else
        {
            int j = i;
            for(j = i; j < nums.size(); ++j)
            {
                if(nums[j] <= nums[i -1])
                break;
            }
            int tmp = nums[i-1];
            nums[i-1] = nums[j-1];
            nums[j -1] = tmp;
            reverse(nums, i, nums.size()-1);
        }
    }
    void reverse(vector<int> & nums, int start, int end)
    {
        while(start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start += 1;
            end -= 1;
        }
    }
};

int main(void)
{
    vector<int> input = {5,1,1};
    Solution sol = Solution();
    sol.nextPermutation(input);
    for(int i : input)
    {
        cout << i << " ";
    }
    cout << endl;
}