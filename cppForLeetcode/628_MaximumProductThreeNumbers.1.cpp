#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1= 0x80000000;
        int max2= 0x80000000;
        int max3= 0x80000000;
        int min1= 0x7fffffff;
        int min2= 0x7fffffff;
        for(int a : nums)
        {
            if (a > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = a;
            }
            else if (a > max2)
            {
                max3 = max2;
                max2 = a;
            }
            else if (a > max3)
            {
                max3 = a;
            }

            if (a < min1)
            {
                min2 = min1;
                min1 = a;
            }
            else if(a < min2)
            {
                min2 = a;
            }
        }
        return max(max1* max2 * max3, min1 * min2 * max1);
    }
};

int main(void)
{
    int a = 0x7fffffff;
    int b = 0x80000000;
    cout << a << " " << b << endl;
}