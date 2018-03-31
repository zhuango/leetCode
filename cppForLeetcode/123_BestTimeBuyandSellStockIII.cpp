#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s0k0 = 0;
        int s0k1 = 0;
        int s1k0 = 0x80000000;
        int s1k1 = 0x80000000;
        for (int a : prices)
        {
            s0k1 = max(s0k1, s1k1 + a);
            s1k1 = max(s1k1, s0k0 - a);
            s0k0 = max(s0k0, s1k0 + a);
            s1k0 = max(s1k0, - a);
        }
        return s0k1;
    }
};

int main(void)
{
}