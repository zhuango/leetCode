#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool recur(string &s1, string &s2, string &s3, unsigned int i1, unsigned int i2, unsigned int i3)
    {
        if( (i3 == s3.size()) && (i1 == s1.size()) && (i2 == s2.size()) )
        {
            return true;
        }
        if (i1 >= s1.size())
        {
            if(s2[i2] == s3[i3])
                return recur(s1, s2, s3, i1, i2+1, i3+1);
            else
                return false;
        }

        if(i2 >= s2.size())
        {
            if(s1[i1] == s3[i3])
                return recur(s1, s2, s3, i1+1, i2, i3+1);
            else
                return false;
        }

        if(s1[i1] == s3[i3])
        {
            if (recur(s1, s2, s3, i1+1, i2, i3+1))
                return true;
        }
        if (s2[i2] == s3[i3])
        {
            if (recur(s1, s2, s3, i1, i2+1, i3+1))
                return true;
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int index_s1 = 0;
        int index_s2 = 0;

        return recur(s1, s2, s3, 0, 0, 0);
    }
};


int main(void)
{
    Solution sol = Solution();
    string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
    cout << sol.isInterleave(s1, s2, s3) << endl;
}