#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        int staticInterval = 2*(numRows-1);
        int interval = staticInterval;
        int tempInter ;
        int start = 0;
        string results;
        int j = 0;
        for(int i = numRows; i >= 1; --i)
        {
            start = numRows - i;
            tempInter = interval;
            j = start;
            while(j < s.size())
            {
                results.push_back(s[j]);
                j += tempInter;
                tempInter = staticInterval - tempInter;
                if (tempInter == 0) tempInter = staticInterval;
            }
            interval -= 2;
            if(interval == 0) interval = staticInterval;
        }
        return results;
    }
};