#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mapping(256, -1);
        int last = -1;
        int maxLength = 0;
        int maxLast = 0;
        char chr;
        for (int i = 0; i < s.size(); ++i)
        {
            chr = s[i];
            if (mapping[chr] > last)
            {
                last = mapping[chr];
            }
            mapping[chr] = i;
            if(i - last > maxLength)
            {
                maxLength = i - last;
                maxLast = last;
            }
        }
        return maxLength;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcbdabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
}