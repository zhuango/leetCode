#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        maxResults = nums[0] * nums[1] * nums[2];

    }

    private:
    int maxResults;
};