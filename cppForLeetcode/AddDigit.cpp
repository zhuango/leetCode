#include "Common.h"

int addDigits(int num) {
    int sum = num;
    int tmp = 0;
    while(sum >= 10)
    {
        tmp = sum;
        sum = 0;
        while(tmp != 0)
        {
            sum += tmp % 10;
            tmp = tmp / 10;
        }
    }
    
    return sum;
}

int addDigits_dr(int num) {
    int result = num - 9 * ((num - 1) / 9);
    return result;
}

int main(void)
{
    cout << addDigits(123123) << endl;
    cout << addDigits_dr(123123) << endl;
    return 0;
}