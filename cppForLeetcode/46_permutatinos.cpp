#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
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
                one_perm.push_back(nums[i]);
                track[i] = 1;
                entry(nums, results, track, one_perm);
                track[i] = 0;
                one_perm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int track[nums.size()];
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
    vector<int> in = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> out = sol.permute(in);
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