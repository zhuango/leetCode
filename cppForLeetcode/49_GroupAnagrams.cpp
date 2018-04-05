#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> strSorted(strs);
        for(auto &s : strSorted)
        {
            sort(s.begin(), s.end());
        }
        map<string, vector<int>> table;
        for (int i = 0; i < strSorted.size(); ++i)
        {
            table[strSorted[i]].push_back(i);
        }
        vector<vector<string>> results;
        vector<string> temp;
        for (auto &pair : table)
        {
            temp.clear();
            for (int i : pair.second)
            {
                temp.push_back(strs[i]);
            }
            results.push_back(temp);
        }
        return results;
    }
};