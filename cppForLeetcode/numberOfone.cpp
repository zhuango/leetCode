#include "Common.h"

int hammingWeight(unsigned int n)
{
    int result = 0;
    while(n != 0)
    {
        result += n % 2;
        n = n / 2;
    }
    return result;
}

int main(void)
{
    cout << hammingWeight(11) << endl;
    cout << hammingWeight(0) << endl;
    cout << hammingWeight(8) << endl;
    cout << hammingWeight(1000) << endl;
    cout << hammingWeight(7) << endl;
    return 0;
}
