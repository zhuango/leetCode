#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k <= 0 || prices.size() == 0) return 0;
        if (k > prices.size())
        {        
            int s0 =0;
            int s1 =0x80000000;
            int temp;
            for (auto a : prices)
            {
                temp = s0;
                s0 = max(s0, s1 + a);
                s1 = max(s1, temp - a);
            }
            return s0;
        }
        vector<vector<int>> s(k, vector<int>(2, 0));
        int i = 0;
        for (int i = 0; i < k; ++i)
        {
            s[i][1] = 0x80000000;
        }
        for (int a: prices)
        {
            s[0][0] = max(s[0][0], s[0][1] + a);
            s[0][1] = max(s[0][1], -a);
            for (i = 1; i < k; ++i)
            {
                s[i][0] = max(s[i][0], s[i][1] + a);
                s[i][1] = max(s[i][1], s[i-1][0] - a);
            }
        }
        return s[k-1][0];
    }
};