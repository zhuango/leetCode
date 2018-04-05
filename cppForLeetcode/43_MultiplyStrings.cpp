#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string multiResult;
        string results = "0";
        int index = 1;
        char c = ' ';
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            c = num1[i];
            multiResult = "";
            multi(c, num2, multiResult);
            add(multiResult, results, results.size() - index);
            index += 1;
        }
        return results;
    }
    void multi(char c, string &num, string &multiResult)
    {
        int jinwei = 0;
        int fator = c - '0';
        int cur = 0;
        for(int i = num.size() - 1; i >= 0; --i)
        {
            cur = fator * (num[i] - '0') + jinwei;
            jinwei = cur / 10;
            cur = cur % 10;
            multiResult = to_string(cur) + multiResult;
        }
        if (jinwei != 0) multiResult = to_string(jinwei) + multiResult;
    }
    void add(string &s1, string &s2, int index)
    {
        int n1 = s1.size();
        int jinwei = 0;
        int cur = 0;
        int i, j;
        for(i = index, j = n1 - 1; i >= 0 && j >= 0; --i, --j)
        {
            cur = jinwei + (s1[j] - '0') + (s2[i] - '0');
            jinwei = cur / 10;
            cur = cur % 10;
            s2[i] = '0' + cur;
        }
        if (j >= 0)
        {
            while (j >= 0)
            {
                cur = jinwei + (s1[j] - '0');
                jinwei = cur / 10;
                cur = cur % 10;

                s2 = to_string(cur) + s2;
                j--;
            }
        }
        if (i >= 0)
        {
            while(i >= 0)
            {
                cur = jinwei + (s2[i] - '0');
                jinwei = cur / 10;
                cur = cur % 10;

                s2[i] = '0' + cur;
                i--;
            }
        }
        if (jinwei != 0) s2 = to_string(jinwei) + s2;
    }
};

int main(void)
{
    Solution sol;
    cout << sol.multiply("123", "456") << endl;
    cout << 123 * 456 << endl;
    //cout << sol.multiply("0", "0") << endl;
}