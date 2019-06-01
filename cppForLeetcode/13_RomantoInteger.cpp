#include <string>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {
        mapping['I'] = 1;
        mapping['V'] = 5;
        mapping['X'] = 10;
        mapping['L'] = 50;
        mapping['C'] = 100;
        mapping['D'] = 500;
        mapping['M'] = 1000;
    }
    int romanToInt(string s) {
       int num = 0;
       int base = 0;
       char c = ' ';
       int curBase = 0;
       for (int i = s.size() - 1; i >= 0; --i)
       {
           c = s[i];
           curBase = mapping[s[i]];
           if (curBase >= base)
           {
               num += curBase;
               base = curBase;
           }
           else
           {
               num -= curBase;
           }
       }
       return num;
    }

private:
    unordered_map<char, int> mapping;
};

int main(void)
{
    Solution sol;
    cout  << sol.romanToInt("DDDD") << endl;
}