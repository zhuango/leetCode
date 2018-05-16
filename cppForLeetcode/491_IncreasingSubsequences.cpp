#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        vector<bool> visited(201, false);
        for(int i = 0; i < nums.size(); ++i)
        {
            cur.push_back(nums[i]);
            dfs(nums, i + 1, cur);
            cur.pop_back();
        }
        return vector<vector<int>>(results.begin(), results.end());
    }
    void dfs(vector<int> &nums, int index, vector<int>& cur)
    {
        for(int i = index; i < nums.size(); ++i)
        {
            if(nums[i] >= cur.back()) 
            {
                cur.push_back(nums[i]);
                results.insert(cur);
                dfs(nums, i + 1, cur);
                cur.pop_back();
            }
        }
    }
    private:
    set<vector<int>> results;
};

int main(void)
{
    set<vector<int>> a;
    a.insert({1});
    a.insert({1});
    for (vector<int> i : a)
    {
        for(int in : i)
            cout << in << " ";
        cout << endl;
    }
}