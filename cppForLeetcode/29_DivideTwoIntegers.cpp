#include <algorithm>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        if (dividend == divisor) return 1;
        if (dividend == 0x80000000 && divisor == -1) return 0x7fffffff;
        int result = 0;
        bool minus = false;

        if ((dividend < 0) ^ (divisor < 0)) minus = true;
        long divi = labs(dividend);
        long dvs = labs(divisor);
        while(divi >= dvs)
        {
            long temp = dvs, multi = 1;
            while(divi > (temp << 1))
            {
                temp <<= 1;
                multi <<= 1;
            }
            divi -= temp;
            result += multi;
        }
        
        return minus ? -result : result;
    }
};