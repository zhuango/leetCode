#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the middle number of the array
     */
    int median(vector<int> &nums) {
        // write your code here
        int median = nums.size() / 2;
        if(nums.size() % 2 == 0) median = nums.size() / 2 -1;
        return findmedian(nums, 0, nums.size()- 1, median);
    }
    int findmedian(vector<int> &num, int start, int end, int medianpos)
    {
        if(start >= end) return num[start];
        int mid = partition(num, start, end);
        if(mid == medianpos) return num[mid];
        if(mid > medianpos) return findmedian(num, start, mid - 1, medianpos);
        else return findmedian(num, mid + 1, end, medianpos);
    }
    int partition(vector<int> &num, int start, int end)
    {
        int povit = num[start];
        int i = start;
        int j = end;
        while(i < j)
        {
            while(num[i] <= povit) i++;
            while(num[j] > povit) j--;
            if(i < j) swap(num[i], num[j]);
        }
        swap(num[j], num[start]);
        return j;
    }
};


int main(void)
{
    vector<int> input = {7,9,4,5};
    Solution sol;
    cout << sol.median(input) << endl;
}