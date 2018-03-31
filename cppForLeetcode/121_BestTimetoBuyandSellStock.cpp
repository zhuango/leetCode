#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s0 = 0;
        int s1 = 0x08000000;
        for (auto a :  prices)
        {
            s0 = max(s0, a + s1);
            s1 = max(s1, -a);
        }
        return s0;
    }
};