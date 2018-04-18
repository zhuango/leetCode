#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> count;
        count[0] = -1;
        int sum = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i]) sum += 1;
            else sum -= 1;
            if(count.find(sum) != count.end())
            {
                result = max(result, i - count[sum]);
            }
            else
            {
                count[sum] = i;
            }
        }
        return result;
    }
};