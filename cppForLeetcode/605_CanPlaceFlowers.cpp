#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> contiZeros;
        int countZeros = 0;
        for(int i = 0; i < flowerbed.size(); ++i)
        {
            if (flowerbed[i] == 0)
            {
                countZeros += 1;
            }
            else
            {
                if (countZeros >= 3) contiZeros.push_back(countZeros);
                countZeros = 0;
            }
        }
        if (countZeros >= 3) contiZeros.push_back(countZeros);
        for (int i = 0; i < contiZeros.size() && n > 0; ++i)
        {
            n -= (contiZeros[i] - 1) / 2;
        }
        if (n == 0) return true;
        else return false;
    }
};