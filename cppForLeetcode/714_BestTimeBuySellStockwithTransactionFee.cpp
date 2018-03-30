#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int s0 = 0;
        int s1 = 0x80000000;
        int temp;
        for (auto a : prices)
        {
            temp = s1;
            s1 = max(s1, s0 - a - fee);
            s0 = max(s0, temp + a);
        }
        return s0;
    }
};