#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<string, bool> table;
        for (string &s : words)
        {
            table[s] = true;
        }
        string result = "";
        for (string &s : words)
        {
            bool find = true;
            for(int i = 0; i < s.size() - 1; ++i)
            {
                if(table.count(s.substr(0, i + 1)) < 1)
                {
                    find = false;
                    break;
                }
            }
            if (find and s.size() >= result.size())
            {
                if(s.size() > result.size() or (s.size() == result.size() and s < result))
                {
                    result = s;
                }
            }
        }
        return result;
    }
};

int main(void)
{
    string a = "abc";
    string b = "abc";
    cout << (a < b) << endl;
    cout << (a > b) << endl;
}