#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<vector<string>> niCountTable(words.size() + 1);
        map<string, int> countTable;
        for(string &s : words)
        {
            countTable[s] += 1;
        }
        for(auto &pair : countTable)
        {
            cout << pair.first << endl;
            niCountTable[pair.second].push_back(pair.first);
        }
        vector<string> results;
        for(auto iter = niCountTable.rbegin(); iter != niCountTable.rend(); ++iter)
        {
            for (string &s : *iter)
            {
                if(k) results.push_back(s);
                else return results;
                k -= 1;
            }
        }
        return results;
    }
};

int main(void)
{
    Solution sol;
    vector<string> input = {"i", "love", "leetcode", "i", "love", "coding"};
    for (auto &str : sol.topKFrequent(input, 2))
    {
        cout << str << endl;
    }
}