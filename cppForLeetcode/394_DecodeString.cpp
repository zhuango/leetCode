#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result = "";
        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(isdigit(c))
            {
                int time = c - '0';
                i += 2;
                int length = 0;
                while(s[i] != ']')
                {
                    i++;
                    length ++;
                }
            }
            else
            {
                result.push_back(c);
            }
        }
    }
};