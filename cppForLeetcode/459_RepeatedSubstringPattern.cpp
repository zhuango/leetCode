#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = 1;
        int n = s.size();
        for(int length = 1; length <= n / 2; ++length)
        {
            if (n % length != 0) continue;
            string repeatStr = s.substr(0, length);
            bool same = true;
            for (int i = 0; i < length; ++i)
            {
                char chr = repeatStr[i];
                for (int j = i; j < n; j += length)
                {
                    if (chr != s[j]) 
                    {
                        same = false;
                        break;
                    }
                }
                if (!same) break;
            }
            if (same) return true;
        }
        return false;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.repeatedSubstringPattern("") << endl;
    cout << sol.repeatedSubstringPattern("aa") << endl;
    cout << sol.repeatedSubstringPattern("aba") << endl;
    cout << sol.repeatedSubstringPattern("abab") << endl;
    cout << sol.repeatedSubstringPattern("abcabcabcabcab") << endl;
}