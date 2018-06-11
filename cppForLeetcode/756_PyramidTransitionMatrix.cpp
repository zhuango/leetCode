#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, string> allowedDict;
        for(string &s : allowed)
        {
            allowedDict[s.substr(0, 2)].push_back(s[2]);
        }
        string higher = "";
        return dfs(allowedDict, bottom, higher, 0);
    }
    bool dfs(unordered_map<string, string> &allowed, string &bottom, string &higher, int index)
    {
        cout << bottom << " " << higher << endl;
        if(bottom.size() == 2)
        {
            if (allowed.count(bottom) > 0) return true;
            else return false;
        }
        string colors = allowed[bottom.substr(index, 2)];
        for(int i = 0; i < colors.size(); ++i)
        {
            higher.push_back(colors[i]);
            if(index == bottom.size() - 2)
            {
                string newHigher= "";
                if (dfs(allowed, higher, newHigher, 0)) return true;
            }
            else
            {
                if(dfs(allowed, bottom, higher, index + 1)) return true;
            }
            higher.pop_back();
        }
        return false;
    }
};

int main(void)
{
    string bottom = "CACAC";
    vector<string> allowed = {"ACB","AAC","AAB","BCD","BCC","BAA","CCD","CCA","CAD","DAD","DAC","DCD","ACD","DCA","ABA","BDA","BDC","BDB","BBA","ADD","ADC","CDB","DDA","CBB","CBC","CBA","CDA","CBD","DBA","DBC","DBD"};
    Solution sol;
    cout << sol.pyramidTransition(bottom, allowed) << endl;
    return 0;
}