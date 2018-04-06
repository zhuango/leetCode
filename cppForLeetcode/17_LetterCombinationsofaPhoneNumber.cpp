#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return results;
        mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, "");
        return results;
    }
    void backtrack(string &digits, int index, string result)
    {
        if(index == digits.size()) 
        {
            results.push_back(result);
            return;
        }
        int mappingIndex = digits[index] - '0';
        for (int i = 0; i < mapping[mappingIndex].size(); ++i)
        {
            backtrack(digits, index + 1, result+mapping[mappingIndex].substr(i, 1));
        }
    }
    private:
    vector<string> mapping;
    vector<string> results;
};