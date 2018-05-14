#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<int> mapping(S.size() + 1, -1);
        for(int i = 0; i < indexes.size(); ++i)
        {
            mapping[indexes[i]] = i;
        }
        for(int index = mapping.size() - 1; index >= 0; --index)
        {
            if(mapping[index] == -1) continue;
            int i = mapping[index];
            string s = sources[i];
            string t = targets[i];
            bool match = true;
            int j = 0;
            while((j + index) < S.size() && S[j + index] == s[j]) j++;
            if(j != s.size()) match = false;
            if (match)
            {
                S = S.substr(0, index) + t + S.substr(index + s.size());
            }
        }
        return S;
    }
};