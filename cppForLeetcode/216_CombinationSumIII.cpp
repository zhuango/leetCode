#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curResult(k, 1);
        backTrack(curResult, 0, 0, n);
        return result;
    }
    void backTrack(vector<int> &curResult, int index, int sum, int n)
    {
        if (sum > n) return ;
        if (index == curResult.size())
        {
            if (sum == n)
            {
                result.push_back(curResult);
            }
            return;
        }
        int i = 0;
        if (index == 0) i = 1;
        else i = curResult[index - 1] + 1;
        for (; i <= 9; ++i)
        {
            sum += i;
            curResult[index] = i;
            backTrack(curResult, index + 1, sum, n);
            sum -= i;
        }
    }
    private:
        vector<vector<int>> result;
};