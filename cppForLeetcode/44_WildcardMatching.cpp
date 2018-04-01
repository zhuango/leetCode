#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p[0] == '*') return true;
        int i = 0;
        int j = 0;
        while(i < s.size() && j < p.size())
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                i++;
                j++;
            }
            else
            {
                if (p[j] == '*')
                {
                    return true;
                }
                return false;
            }
        }
        if (i == s.size() && j == p.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};