#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nn;
        int temp = num;
        while(temp > 0)
        {
            nn.push_back(temp % 10);
            temp = temp / 10;
        }
        int dirMost = 0;
        int prev = 0;
        int cur = 0;
        int curIndex = 0;
        for(int i = 0; i < nn.size(); ++i)
        {
            if (nn[i] > cur)
            {
                curIndex = i;
                cur = nn[i];
            }
            else if (nn[i] < cur)
            {
                prev = curIndex;
                dirMost = i;
            }
        }
        cur = nn[dirMost];
        nn[dirMost] = nn[prev];
        nn[prev] = cur;
        int result = 0;
        for(int i = nn.size() - 1; i >= 0; --i)
        {
            result = result * 10 + nn[i];
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.maximumSwap(12345) << endl;
}