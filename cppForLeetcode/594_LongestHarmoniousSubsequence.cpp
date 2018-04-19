#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        unordered_map<int, int> count;
        for(int i : nums)
        {
            count[i] += 1;
        }
        for(auto &pair : count)
        {
            if (count.find(pair.first - 1) != count.end())
                maxLength = max(maxLength, pair.second + count[pair.first - 1]);
        }
        return maxLength;
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {1,2,1,3,0,0,2,2,1,3,3};
    cout << sol.findLHS(input) << endl;
}