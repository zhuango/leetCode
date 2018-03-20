#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results{{}};
        if (nums.empty()) return results;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        results.push_back({nums[0]});
        int lastStart = 1;
        int setStart = 0;
        int setEnd = 0;
        for (int i = 1; i < nums.size() ;++i)
        {
            if (nums[i] == nums[i-1]) setStart = lastStart;
            else  setStart = 0;
            lastStart = results.size();
            setEnd = results.size();
            while(setStart < setEnd)
            {
                temp = results[setStart];
                temp.push_back(nums[i]);
                results.push_back(temp);
                setStart += 1;
            }
        }
        return results;
    }
};