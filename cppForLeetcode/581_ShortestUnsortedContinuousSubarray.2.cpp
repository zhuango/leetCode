#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size(), beg = -1, end = -2, mina = nums[n-1], maxa = nums[0];
    for (int i=1;i<n;i++) {
      maxa = max(maxa, nums[i]);
      mina = min(mina, nums[n-1-i]);
      if (nums[i] < maxa) end = i;
      if (nums[n-1-i] > mina) beg = n-1-i; 
    }
    return end - beg + 1;
    }
};

int main(void)
{
    // vector<int> input = {2,6,4,8,10,9,15};
    vector<int> input = {2,2, 2, 3, 2, 2};
    Solution sol;
    int results = sol.findUnsortedSubarray(input);
    cout << results << endl;
}