#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string results(path);
        stack<int> slash;
        int index = 0;
        int indexResults = 0;
        int n = path.size();
        while(index < n)
        {
            while(path[index] == '/' && index < n) index ++;
            if (n == index) break;

            if(path[index] == '.')
            {
                if (index + 1 == n || path[index + 1] == '/')
                {
                    index += 1;
                    continue;
                }
                else if (index + 1 < n && path[index + 1] == '.')
                {
                    if (index + 2 == n || path[index + 2] == '/')
                    {
                        if (slash.empty())
                        {
                            indexResults = 0;
                        }
                        else
                        {
                            indexResults = slash.top();
                            slash.pop();
                        }
                        index += 2;
                        continue;
                    }
                }
            }
            results[indexResults] = '/';
            slash.push(indexResults);
            indexResults ++;
            while(path[index] != '/' && index < n) results[indexResults++] = path[index++];
        }
        return results.substr(0, max(indexResults, 1));
    }
};

int main(void)
{
    Solution sol;
    cout << sol.simplifyPath("/home/sss/.e/../../../") << endl;
    cout << sol.simplifyPath("/home/sss/.e/") << endl;
    cout << sol.simplifyPath("/home/sss") << endl;
    cout << sol.simplifyPath("/home/sss/.") << endl;
    cout << sol.simplifyPath("/home/sss/..") << endl;
    cout << sol.simplifyPath("/home/sss/.,") << endl;
    cout << sol.simplifyPath("/home//sss/.,") << endl;
    cout << sol.simplifyPath("/home//sss/b.,/") << endl;
    cout << sol.simplifyPath("/home//sss/..sd/") << endl;
    cout << sol.simplifyPath("/sdf/sf/.../sd/") << endl;
}