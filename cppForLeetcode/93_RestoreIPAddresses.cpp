#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        l = s.size();
        if (l < 4 || l > 12) return results;
        backtrack(s, 0, "", 0);
        return results;
    }
    void backtrack(string &s, int index, string add, int segCount)
    {
        if (segCount == 4)
        {
            if (index == l)
            {
                results.push_back(add.substr(0, add.size()-1));
            }
            else
            {
                return;
            }
        }
        if (index >= l) return;
        string subStr = s.substr(index, 1);
        int curAdd = atoi(subStr.c_str());
        if (curAdd <= 255) backtrack(s, index + 1, add + subStr + ".", segCount + 1);
        if (subStr[0] == '0') return;

        if (index + 1 >= l) return ;
        subStr = s.substr(index, 2);
        curAdd = atoi(subStr.c_str());
        if (curAdd <= 255) backtrack(s, index + 2, add + subStr + ".", segCount + 1);

        if (index + 2 >= l) return ;
        subStr = s.substr(index, 3);
        curAdd = atoi(subStr.c_str());
        if (curAdd <= 255) backtrack(s, index + 3, add + subStr + ".", segCount + 1);
    }

    private:
    vector<string> results;
    int l;
};

int main(void)
{
    Solution sol;
    for(string &s : sol.restoreIpAddresses("010010"))
    {
        cout << s << endl;
    }
    return 0;
}