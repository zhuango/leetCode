#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int countZeros = 1;
        for(int i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 0)
            {
                countZeros += 1;
            }
            else
            {
                if (countZeros >= 3) n -= (countZeros - 1) / 2;
                countZeros = 0;
            }
        }
        if (countZeros >= 2) n -= (countZeros + 1- 1) / 2;
        return n <= 0;
    }
};