#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int count = 0;
        int i = 1;

        while(i < S.size())
        {
            count = 0;
            vector<int> curR;
            while(i < S.size() && S[i] != S[i-1]) i++;
            count += 1;
            curR.push_back(i - 1);
            while(i < S.size() && S[i] == S[i-1]) 
            {
                count += 1;
                i ++;
            }
            curR.push_back(i - 1);
            if(count >= 3)
            {
                result.push_back(curR);
            }
        }
        return result;
    }
};

int main(void)
{
    //string input = "abcdddeeeeaabbbcd";
    //string input = "abbxxxxzzy";
    string input = "addddddddabcdddddddddd";
    Solution sol;
    for(auto &a : sol.largeGroupPositions(input))
    {
        for(int i : a)
        {
            cout << i << " " ;
        }
        cout << endl;
    }
}