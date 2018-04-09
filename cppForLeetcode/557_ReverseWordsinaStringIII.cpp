#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int length = s.size();
        int start = 0;
        while(i < s.size())
        {
            while(i < length && isspace(s[i])) i++;
            start = i;
            while(i < length && !isspace(s[i])) i++;
            swap(s, start, i - 1);
        }
        return s;
    }
    void swap(string &s, int start, int end)
    {
        char temp;
        while(start < end)
        {
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start ++;
            end --;
        }
    }
};