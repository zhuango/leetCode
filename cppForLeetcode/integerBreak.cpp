#include "Common.h"

int integerBreak(int n)
{
    int base;
    int rest;
    int resulttmp = 0;
    int result = 0;

    for(int i = 2; i <= n; ++i)
    {
        base = n / i;
        rest = n % i;
        resulttmp = pow(base + 1, rest);
        resulttmp *= pow(base, i - rest);
        if(resulttmp > result)
            result = resulttmp;
    }
    return result;
}

int main(void)
{
    cout << integerBreak(1000) << endl;
    cout << integerBreak(2) << endl;
    cout << integerBreak(10) << endl;

    return 0;
}
