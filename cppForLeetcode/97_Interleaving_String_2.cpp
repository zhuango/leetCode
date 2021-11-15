#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
        return false;
        vector<vector<bool>>  table(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        table[0][0] = true;
        for(int i = 0; i < s1.size() + 1; ++i)
        {
            for (int j = 0; j < s2.size() + 1; ++j)
            {
                if (i == 0 && j == 0)
                {
                    table[i][j] = true;
                }
                else
                {
                    if(j > 0 && s3[i + j - 1] == s2[j - 1] && table[i][j-1] == true)
                    {
                        table[i][j] = true;
                    }
                    if (i > 0 && s3[i + j - 1] == s1[i - 1] && table[i-1][j] == true)
                    {
                        table[i][j] = true;
                    }
                }
            }
            
        }
        return table[s1.size()][s2.size()];
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