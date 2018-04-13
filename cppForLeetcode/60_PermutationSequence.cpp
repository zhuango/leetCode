#include <string>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> used(10, false);
        K = k;
        backtrack(n, 0, used);
        return to_string(result);
    }
    void backtrack(int n, int cur, vector<bool> &used)
    {
        if (K == 0)
        {
            return; 
        }
        bool flag = false;
        for(int i = 1; i <= n; ++i)
        {
            if (used[i]) continue;
            else flag = true;
            used[i] = true;
            backtrack(n, cur * 10 + i, used);
            used[i] = false;
        }
        if(!flag)
        {
            K -= 1;
            if (K == 0)
            {
                result = cur;
            }
        }
    }
    private:
    int result;
    int K;
};