#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> uglyNumber(1, 1);
        vector<int> pointers(primes.size(), 0);
        int minu;
        vector<int> minuIndex;
        int temp =0;
        while (uglyNumber.size() < n)
        {
            minu = uglyNumber[pointers[0]] * primes[0];
            minuIndex.clear();
            minuIndex.push_back(0);
            for(int i = 1; i < pointers.size(); ++i)
            {
                temp = uglyNumber[pointers[i]] * primes[i];
                if (temp < minu)
                {
                    minuIndex.clear();
                    minuIndex.push_back(i);
                    minu = temp;
                }
                else if(temp == minu)
                {
                    minuIndex.push_back(i);
                }
            }
            uglyNumber.push_back(minu);
            for(auto index : minuIndex)
            {
                pointers[index] += 1;
            }
        }
        return uglyNumber.back();
    }
};

int main(void)
{
    vector<int> pointers(1000000, 0);
    Solution sol;
    vector<int> input = {2,3};
    cout << sol.nthSuperUglyNumber(10000, input) << endl;
}