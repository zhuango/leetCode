#include <iostream>
using namespace std;


class Solution {
public:
    int divide(int a, int b) {
        // 2^32 overflow
        if (a == 0x80000000 && b == -1) return 0x7fffffff;
        if (a == b) return 1;
        int minus = 0;
        // get the sign indicator.
        if ((a < 0) ^ (b < 0))
        {
            minus = 1;
        }
        // negative numbers has no overflow risk.
        if (a > 0) a = -a;
        if (b > 0) b = -b;

        int results = 0;
        while(a <= b)
        {
            int tmp = b;
            // -2147483648 / 1 = -2147483648 = -2^32 overflow.
            int times = -1;
            //overflow check: tmp + tmp = 0xc0000000 + 0xc0000000 = 0x80000000
            while (tmp >= 0xc0000000 && a <= tmp + tmp)
            {
                tmp += tmp;
                times += times;
            }
            a -= tmp;
            results += times;
        }
        
        if (minus == 0) return -results;
        else return results;
    }
};


int main(void)
{
    Solution sol = Solution();
    cout << sol.divide(-2147483648, 1) << endl;
}