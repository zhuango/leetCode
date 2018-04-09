#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int twoK = 2*k;
        int firstK = 0;
        int length = s.size();
        string result = "";
        int j = 0 ;
        for(int i = 0; i < length; i += twoK)
        {
            firstK = min(length, i + k);
            for(j = firstK - 1; j >= i; --j)
            {
                result.push_back(s[j]);
            }

            result += s.substr(firstK, min(length, i + twoK) - firstK);
        }
        return result;
    }
};