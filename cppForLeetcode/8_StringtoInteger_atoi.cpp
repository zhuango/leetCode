#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int MAXINT = 0x7fffffff;
        int MININT = 0x80000000;
        bool greaterThanZero = true;
        int i = 0;
        while(str[i] == ' ') i++;
        if (str[i] == '+') i++;
        else if (str[i] == '-') 
        {
            greaterThanZero = false;
            i++;
        }
        int results = 0;
        int prev = 0;
        while(i < str.size())
        {
            if (isdigit(str[i]))
            {
                prev = results;
                results = results * 10 + (str[i] - '0');
                if (results / 10 != prev)
                {
                    return greaterThanZero ? MAXINT : MININT;
                }
            }
            else
            {
                break;
            }
            i += 1;
        }
        return greaterThanZero ? results : -results;
    }
};


int main(void)
{
    ///////////////2147483647
    string s= "    10522545459";
    Solution sol;
    cout << sol.myAtoi(s) << endl;
}