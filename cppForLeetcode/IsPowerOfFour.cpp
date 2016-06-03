#include "Common.h"

bool IsPowerOfFour(int n)
{
    return fmod(log10(n) / log10(4), 1) == 0;
}

int main(void)
{
    cout << IsPowerOfFour(64) << endl;
    cout << IsPowerOfFour(16) << endl;
    cout << IsPowerOfFour(6) << endl;
}