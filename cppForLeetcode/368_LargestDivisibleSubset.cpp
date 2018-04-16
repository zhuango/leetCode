#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, vector<int>> table;
        table[-1] = {};
        int maxLength = 0;
        int maxLkey = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            maxLength = 0;
            maxLkey = -1;
            for(auto &pair : table)
            {
                if (pair.second.size() >= maxLength && nums[i] % pair.first == 0)
                {
                    maxLength = pair.second.size();
                    maxLkey = pair.first;
                }
            }
            table[nums[i]] = table[maxLkey];
            table[nums[i]].push_back(nums[i]);
        }

        maxLength = 0;
        maxLkey = -1;
        for(auto &pair : table)
        {
            if(pair.second.size() > maxLength)
            {
                maxLength = pair.second.size();
                maxLkey = pair.first;
            }
        }
        return table[maxLkey];
    }
};