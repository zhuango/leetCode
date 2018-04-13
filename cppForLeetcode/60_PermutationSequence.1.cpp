#include <string>
#include <list>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        result = "";
        vector<bool> ss(n + 1, false);
        dfs(n, 1, 1, k, ss);
        return result;
    }
    int dfs(int n, int curN, int curRank, int k, vector<bool> &ss)
    {
        if (curN > n) return k;
        k = dfs(n, curN + 1, curRank*curN, k, ss);
        int yu = k % curRank;
        int r = k / curRank + (yu ? 1 : 0);
        int count = 0;
        for(int i = 1; i < ss.size(); ++i)
        {
            if(ss[i]) continue;
            else
            {
                count += 1;
                if (count >= r) 
                {
                    result += to_string(i);
                    ss[i] = true;
                    break;
                }
            }
        }
        return yu ? yu : curRank;
    }
    private:
    string result;
};

int main(void)
{
    Solution sol;
    cout << sol.getPermutation(8, 8590) << endl;
    cout << sol.getPermutation(3, 6) << endl;
}
// 1234
// 1243
// 1324
// 1342
// 1423
// 1432
// 2134
// 2143
// 2314
// 2341
// 2413
// 2432
// 12345678

// 12
// 21