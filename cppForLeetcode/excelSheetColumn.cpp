#include "Common.h"

int titleToNumber(string s) {
    unsigned int maxIndex  = s.size()-1;
    int result = 0;
    for(unsigned int i = 0; i < s.size(); ++i)
    {
        char cur = s[maxIndex - i];
        result += (cur - 'A' + 1) * pow(26, i);
    }
    return result;
}

int main(void)
{
    cout << titleToNumber("A") << endl;
    cout << titleToNumber("AA") << endl;
    cout << titleToNumber("AZ") << endl;
    cout << titleToNumber("ABA") << endl;
}