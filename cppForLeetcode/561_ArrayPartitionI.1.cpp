#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> baseSort(20001, 0);
        for(int n : nums)
        {
            baseSort[n + 10000] ++;
        }
        int sum = 0;
        bool flag = true;
        for (int i = 0; i < 20001;)
        {
            if (baseSort[i] > 0 && flag)
            {
                sum += i - 10000;
                flag = false;
                baseSort[i] --;
            }
            else if (baseSort[i] > 0 && !flag)
            {
                flag = true;
                baseSort[i] --;
            }
            else i ++;
        }
        return sum;
    }
};