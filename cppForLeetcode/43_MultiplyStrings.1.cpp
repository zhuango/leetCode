#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "";

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        std::string res(num1.size() + num2.size(),'0');
        for (int j = 0; j < num2.size(); j++)
        {
            int tmp = 0;
            int val = num2[j] - '0';
            for (int i = 0; i < num1.size(); i++)
            {
                tmp += (num1[i] - '0') * val + (res[i + j] - '0');
                res[i + j] = tmp % 10 + '0';
                tmp /= 10;
            }
            if (tmp != 0)
                res[num1.size() + j] = tmp + '0';
        }
        std::reverse(res.begin(), res.end());
        int count = 0;
        while (count < res.size() - 1 && res[count] == '0')
            count++;
        res.erase(0, count);
        return res;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.multiply("123", "456") << endl;
    cout << 123 * 456 << endl;
    //cout << sol.multiply("0", "0") << endl;
}