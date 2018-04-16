#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || z <= (long long)x + y && z % __gcd(x, y) == 0;
    }
};
int main(void)
{
    Solution sol;
    cout << sol.canMeasureWater(3, 5, 2) << endl;
}