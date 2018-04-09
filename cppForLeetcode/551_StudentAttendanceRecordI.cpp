#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = 0;
        for (char c : s)
        {
            if(c == 'L') countL ++;
            else if(c == 'A') countA ++;
        }
        return !(countA > 1 or countL > 2);
    }
};