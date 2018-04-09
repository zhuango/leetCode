#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        if (n == 0) return -1;
        vector<int> bits;
        int tempN = n;
        while(tempN)
        {
            bits.push_back(tempN % 10);
            tempN = tempN / 10;
        }
        int bi = bits[0];
        int mini;
        int minIndex = 0;
        for(int i = 1; i < bits.size(); ++i)
        {
            bi = bits[i];
            //1999999999
            mini = 0x7fffffff;
            for (int j = i - 1; j >= 0; --j)
            {
                if (bits[j] > bi && bits[j] < mini)
                {
                    mini = bits[j];
                    minIndex = j;
                }
            }
            cout << mini << endl;
            if (mini != 0x7fffffff)
            {
                swap(bits[i], bits[minIndex]);
                sort(bits.begin(), bits.begin() + i, [](int a, int b){return a > b;});
                int result = 0;
                for(int j = bits.size() - 1; j >= 0; --j)
                {
                    result = result * 10 + bits[j];
                }
                if (result < n) return -1;
                return result;
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.nextGreaterElement(21) << endl;
}