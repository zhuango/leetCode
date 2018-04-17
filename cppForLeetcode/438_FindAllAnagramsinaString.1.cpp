#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> results;
        int length = p.size();
        if(s.size() < length) return results;
        vector<int> charTable(26, 0);
        vector<int> tempTable(26, 0);
        for(int i = 0; i < length; ++i)
        {
            charTable[p[i] - 'a'] ++;
            tempTable[s[i] - 'a'] ++;
        }
        bool same;
        for(int i = length - 1; i < s.size();)
        {
            if (tempTable == charTable)
            {
                results.push_back(i - length + 1);
            }
            i ++;
            tempTable[s[i - length] - 'a'] -= 1;
            tempTable[s[i] - 'a'] += 1;
        }
        return results;
    }
};

int main(void)
{
    string ps = "liuzhuang";
    string pa(ps.rbegin(), ps.rend());
    Solution sol;
    for(auto &s : sol.findAnagrams("cbaebabacd", "abc"))
    {
        cout << s << endl;
    }
}