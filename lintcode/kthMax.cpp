#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        return findKth(nums, 0, nums.size()-1, n-1);
    }
    int findKth(vector<int> &num, int start, int end, int k)
    {
        if(start >= end) return num[start];
        int mid = partition(num, start, end);
        cout << mid << endl;
        if(mid == k) return num[k];
        if(mid > k) return findKth(num, start, mid - 1, k);
        else return findKth(num, mid + 1, end, k);
    }
    int partition(vector<int> &num, int start, int end)
    {
        int povit = num[end];
        int i = start;
        int j = end;
        while(i < j)
        {
            while(num[i] > povit) i++;
            while(num[j] <= povit) j--;
            if(i < j) swap(num[i], num[j]);
        }
        swap(num[i], num[end]);
        return i;
    }
};

int main(void)
{
    vector<int> input = {32, 12, 34, 23, 7, 43, 345, 34, 2, 65};
    Solution sol;
    cout << sol.kthLargestElement(3, input) << endl;
    sort(input.begin(), input.end());
    cout << input[input.size() - 3] << endl;
}