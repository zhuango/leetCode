#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int limit = 100;
        int curLine = 0;
        vector<int> results(2, 0);
        for(char i : S)
        {
            curLine += widths[i -'a'];
            if(curLine > limit)
            {
                results[0] += 1;
                curLine = widths[i-'a'];
            }
            else if(curLine == limit)
            {
                results[0] += 1;
                curLine = 0;
            }
        }
        if (curLine > 0)
        {
            results[1] = curLine;
            results[0] += 1;
        }
        else if (results[0])
        {
            results[1] = limit;
        }
        return results;
    }
};