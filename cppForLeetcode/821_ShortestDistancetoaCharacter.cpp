#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> indexes;
        vector<int> results;
        indexes.push_back(-1 * (S.size() + 1));
        for(int i = 0; i < S.size(); ++i)
        {
            if(S[i] == C)
            {
                indexes.push_back(i);
            }
        }
        indexes.push_back(0x7fffffff);
        char keyCount = 0;
        for(int i = 0; i < S.size(); ++i)
        {
            if(S[i] == C)
            {
                keyCount += 1;
                results.push_back(0);
            }
            else
            {
                results.push_back(min(i - indexes[keyCount], indexes[keyCount + 1] - i));
            }
        }
        return results;
    }
};