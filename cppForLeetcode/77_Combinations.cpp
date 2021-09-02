#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void recur(vector<vector<int>> &res, int start, int n, int k, vector<int> &temp)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        for (int i = start; i <= n - (k - temp.size()-1); ++i)
        {
            temp.push_back(i);
            recur(res, i+1, n, k, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        recur(res, 1, n, k, temp);
        return res;
    }
};

int main(void)
{
    Solution sol = Solution();
    vector<vector<int>> out = sol.combine(20, 10);
    for (auto &a : out)
    {
        for(int i : a)
        {
            cout << i << " " ;
        }
        cout << endl;
    }

    return 0;
}