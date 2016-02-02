#include "Common.h"

class IsPowerOfThree
{
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n) / log10(3), 1) == 0;
    }
};