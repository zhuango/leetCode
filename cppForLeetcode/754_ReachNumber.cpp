#include<vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int cur = 0;
        int step = 0;
        target = abs(target);
        while(cur < target)
        {
            step += 1;
            cur += step;
        }
        
        while((cur - target) % 2 != 0)
        {
            step += 1;
            cur += step;
        }
        return step;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.reachNumber(1) << endl;
}
