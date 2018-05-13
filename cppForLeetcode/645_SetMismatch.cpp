#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> results;
        vector<bool> mapping(nums.size() + 1, false);
        for(int i : nums)
        {
            if(mapping[i])
            {
                results.push_back(i);
            }
            mapping[i] = true;
        }
        for(int i = 1; i < nums.size() + 1; ++i)
        {
            if(!mapping[i])
            {
                results.push_back(i);
                return results;
            }
        }
    }
};