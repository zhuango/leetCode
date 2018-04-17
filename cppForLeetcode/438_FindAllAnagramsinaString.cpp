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
        unordered_map<char, int> charTable;
        unordered_map<char, int> tempTable;
        for(int i = 0; i < length; ++i)
        {
            charTable[p[i]] ++;
            tempTable[s[i]] ++;
        }
        bool same;
        for(int i = length - 1; i < s.size();)
        {
            same = true;
            for(auto &pair : charTable)
            {
                if(tempTable[pair.first] != pair.second)
                {
                    same = false;
                    break;
                }
            }
            if (same)
            {
                results.push_back(i - length + 1);
            }
            i ++;
            tempTable[s[i - length]] -= 1;
            tempTable[s[i]] += 1;
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