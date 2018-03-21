#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, tmp);
        return results;
    }
    void dfs(vector<int> &candidates, int index, int target, vector<int> &temp)
    {
        if (target == 0)
        {
            results.push_back(temp);
            return;
        }
        if (target < 0) return;
        for (int i = index; i < candidates.size(); ++i)
        {
            if (i > index && candidates[i] == candidates[i -1]) continue;
            temp.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i], temp);
            temp.pop_back();
        }
    }
    private:
    vector<vector<int>> results;
};