#include <string>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstCapitals = false;
        bool hasLower = false;
        bool hasUpper = false;
        bool prevSpace = true;
        for(char c : word)
        {
            if (isspace(c))
            {
                firstCapitals= false;
                hasLower = false;
                hasUpper = false;
                prevSpace = true;
            }
            else
            {
                if (isupper(c))
                {
                    if (prevSpace) firstCapitals = true;
                    else hasUpper = true;
                }
                else if (islower(c)) hasLower = true;
                prevSpace = false;

                if (hasLower && hasUpper)
                {
                    return false;
                }
            }
        }
        return true;
    }
};