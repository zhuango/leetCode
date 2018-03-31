#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int temp1 = nums[n] * nums[n-1] * nums[n-2];
        int temp2 = nums[0] * nums[1] * nums[n];
        return temp1 > temp2 ? temp1 : temp2;
    }
};