#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for(int i = 1; i <= N; ++i)
        {
            if (isgood(i)) count ++;
        }
        return count;
    }
    bool isgood(int a)
    {
        bool hasInvalid = false;
        bool hasCanRot = false;
        int temp =0;
        while(a)
        {
            temp = a % 10;
            if (canRotate.find(temp) != canRotate.end())
            {
                hasCanRot = true;
            }
            else if (same.find(temp) == same.end())
            {
                hasInvalid = true;
            }
            a = a / 10;
        }
        if (hasInvalid) return false;
        else if (hasCanRot) return true;
        else return false;
    }
    private:
    set<int> canRotate={2, 5, 6, 9};
    set<int> same = {0, 1, 8};
};