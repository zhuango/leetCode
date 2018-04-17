#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> results;
        unordered_map<string, int> counter;
        int i = 9;
        for(i = 9; i < s.size(); ++i)
        {
            string temp = s.substr(i - 9, 10);
            counter[temp] += 1;
        }
        for(auto &pair : counter)
        {
            if (pair.second > 1)
            {
                results.push_back(pair.first);
            }
        }
        return results;
    }
};

int main(void)
{
    Solution sol;
    for(string s : sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
    {
        cout << s << endl;
    }
    return 0;
}