#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> table(n + 1, 1);
        int start = 0;
        int end = 0;
        int mm = 0;
        int powInt = 0;
        double powReal =0.0;
        powReal = pow(n, 0.5);
        powInt = powReal;
        if(powInt == powReal) 
        {
            return 1;
        }
        for(int i = 2; i <= n; ++i)
        {
            powReal = pow(i, 0.5);
            powInt = powReal;
            if(powReal - powInt == 0.0) 
            {
                table[i] = 1;
                continue;
            }
            start = 1;
            end = start * start;
            mm = table[end] + table[i - end];
            while(end < i)
            {
                mm = min(mm, table[end] + table[i - end]);
                start ++;
                end = start * start;
            }
            table[i] = mm;
        }
        return table[n] ;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.numSquares(12) << endl;
    cout << sol.numSquares(10000) << endl;
    cout << sol.numSquares(13) << endl;
    cout << sol.numSquares(15) << endl;
    cout << sol.numSquares(100001) << endl;
}