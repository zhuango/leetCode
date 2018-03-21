#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while(slow!=fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            // same distance from slow or fast to loop entry.
            fast = 0;
            while(slow != fast)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};