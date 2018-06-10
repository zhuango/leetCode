#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int mm = 0x7fffffff;
        for(int i = shifts.size()-1; i > 0; --i)
        {
            shifts[i-1] += shifts[i] % 26;
        }
        for(int i = 0; i < S.size(); ++i)
        {
            int from = 'z' - S[i];
            shifts[i] = shifts[i] % 26;
            if(shifts[i] > from)
            {
                S[i] = 'a' + (shifts[i] - from - 1);
            }
            else
            {
                S[i] = S[i] + shifts[i];
            }
        }
        return S;
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513};
    

    cout << sol.shiftingLetters("mkgfzkkuxownxvfvxasy", input) << endl;
}