#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result = "";
        stack<int> times;
        stack<string> starts;
        for(int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if(isdigit(c))
            {
                int j = i;
                while(isdigit(c))  c = s[++j];
                times.push(stoi(s.substr(i, j)));
                starts.push("");
                i = j;
            }
            else if(c == ']')
            {
                string repeatS = starts.top();
                int time = times.top();
                starts.pop();
                times.pop();
                
                if(times.empty()) for (int index = 0; index < time; ++index) result += repeatS;
                else for (int index = 0; index < time; ++index)  starts.top().append(repeatS);
            }
            else if(times.empty())
            {
                result.push_back(c);
            }
            else
            {
                starts.top().push_back(c);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.decodeString("3[a]2[bc]") << endl;
    cout << sol.decodeString("3[a2[c]]") << endl;
    cout << sol.decodeString("2[abc]3[cd]ef") << endl;
    cout << sol.decodeString("asfhwewf") << endl;
    cout << sol.decodeString("a2[a3[E]bc]3[cd]ef") << endl;
    cout << sol.decodeString("") << endl;
    cout << sol.decodeString("1[w]") << endl;
    cout << sol.decodeString("10[leetcode]") << endl;
}