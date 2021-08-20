#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    void entry(vector<int> &nums, vector<vector<int>> &results, int track[], vector<int> &one_perm)
    {
        if (one_perm.size() == nums.size())
        {
            results.push_back(one_perm);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if (!track[i])
            {
                // duplicates in current iteration need to be skipped.
                // !track[i - 1] == true: the last one has already been processed, so the current one need to be skipped.
                // track[i - 1] == true: nums[i] is used in the previous iterations and that should not effect this iteration.
                if (i > 0 && nums[i] == nums[i-1] && !track[i - 1])
                    continue;
                one_perm.push_back(nums[i]);
                track[i] = 1;
                entry(nums, results, track, one_perm);
                track[i] = 0;
                one_perm.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int track[nums.size()];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i) track[i] = 0;
        vector<vector<int>> results;
        vector<int> one_perm;
        entry(nums, results, track, one_perm);
        
        return results;
    }
};

int main(void)
{
    Solution sol = Solution();
    vector<int> in = {1, 2, 2, 3};
    vector<vector<int>> out = sol.permuteUnique(in);
    for(auto& l : out)
    {
        for (int i : l)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << out.size() << endl;

    return 0;
}