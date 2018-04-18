#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> results;
        vector<int> table(26, 0);
        string s0 = "qwertyuiop";
        for(char c : s0) table[c - 'a'] = 0;
        string s1 = "asdfghjkl";
        for(char c : s1) table[c - 'a'] = 1;
        string s2 = "zxcvbnm";
        for(char c : s2) table[c - 'a'] = 2;
        for(string &s : words)
        {
            bool oneline = true;
            int line = table[tolower(s[0]) - 'a'];
            for(char c : s)
            {
                if (table[tolower(c) - 'a'] != line)
                {
                    oneline = false;
                    break;
                }
            }
            if(oneline) results.push_back(s);
        }
        return results;
    }
};