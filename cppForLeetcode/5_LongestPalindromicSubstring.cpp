#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string T = "^";
        //                     C--R
        // from "babad" -> "^#b#a#b#a#d#$"
        // In this format, the distance from right boundary to the current center index is the length of Palindromic.
        // For example, say the first 'a' in the string is the center. the right boundary if the '#' right behand 'b'.
        // The distance is R - C = 3 = the length of "bab".
        for (int i = 0; i < s.size(); ++i)
        {
            T += "#" + s.substr(i, 1);
        }
        T += "#$";
        int n = T.size();

        vector<int> table(n, 0);
        // current center.
        int center = 0;
        // right boundry of current center.
        int right = 1;
        // the mirror index the current index.
        int mirror = 0;
        for(int i = 1; i < n-1; ++i)
        {
            // get the mirror index.
            mirror = center - (i - center);
            table[i] = right > i ? min(right - i, table[mirror]): 0;
            while(T[i + 1 + table[i]] == T[i - 1 - table[i]])  table[i] ++;
            if (i + table[i] > right)
            {
                center = i;
                right = i + table[i];
            }
        }
        int maxlength = 0;
        center = 0;
        // find max length.
        for (int i = 1; i < n-1; ++i)
        {
            if (table[i] > maxlength)
            {
                maxlength = table[i];
                center = i;
            }
        }
        return s.substr((center - 1 - maxlength) / 2, maxlength);
    }
};

int main(void)
{
    string s = "liuzhaung";
    string s1(s.rbegin(), s.rend());
    cout << s1 << endl;
    map<float, int> ss;
    ss[0.34] = 10;
    cout << ss[0.34] << endl;

    s = "tattarrattat";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl;
}