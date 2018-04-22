#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, bool> bannedStrs;
        unordered_map<string, int> notbannedStrs;
        for(auto &s : banned)
        {
            bannedStrs[s] = true;
        }
        int length = paragraph.size();
        for(int i = 0; i < length; ++i)
        {
            paragraph[i] = tolower(paragraph[i]);
        }
        int index = 0;
        int end = 0;
        while(end < length && index < length)
        {
            while(index < length &&  !isalpha(paragraph[index])) index ++;
            if (index == length) break;
            end = index;
            while(end < length && (isalpha(paragraph[end]))) end ++;
            string tempStr = paragraph.substr(index, end - index);
            cout << tempStr <<  endl;
            if(bannedStrs.find(tempStr) == bannedStrs.end())
            {
                notbannedStrs[tempStr] ++;
            }
            index = end;
        }
        string result;
        int maxCount = 0;
        for(auto & p : notbannedStrs)
        {
            if (p.second > maxCount)
            {
                result = p.first;
                maxCount = p.second;
            }
        }
        return result;
    }
};
int main(void)
{
//     "Bob hit a ball, the hit BALL flew far after it was hit."
// ["hit"]
    Solution sol;
    vector<string> input = {"hit"};
    string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
    //cout << sol.mostCommonWord(str, input) << "SSSSSSSS" <<  endl;
    cout << sol.mostCommonWord("a.", input) << "SSSSSSSS" <<  endl;
}