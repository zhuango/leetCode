#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int index = 0;
        int length = s.size();
        while(index < length)
        {
            while(index < length && isspace(s[index])) index ++;
            if (index == length) break;
            count += 1;
            while(index < length && !isspace(s[index])) index ++;

        }
        return count;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.countSegments("Hello , my name is John") << endl;
}