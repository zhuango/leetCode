#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        map<char, vector<int>> mapping;
        int count = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            mapping[S[i]].push_back(i);
        }
        int prevIndex = 0;
        int tempIndex = 0;
        for (string &word : words)
        {
            if (mapping[word[0]].empty()) continue;
            prevIndex = mapping[word[0]][0];
            tempIndex = prevIndex;
            count += 1;
            for (int j = 1; j < word.size(); ++j)
            {
                for (auto index : mapping[word[j]])
                {
                    if (index > prevIndex)
                    {
                        tempIndex = index;
                        break;
                    }
                }
                if (tempIndex == prevIndex)
                {
                    count -= 1;
                    break;
                }
                else
                {
                    prevIndex = tempIndex;
                }
            }
        }
        return count;
    }
};