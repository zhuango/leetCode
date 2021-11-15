#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size() - 1;
        int lb = b.size() - 1;
        int carry = 0;
        string results;
        while(la >= 0 || lb >= 0)
        {
            int aa = la >= 0 ? a[la] - '0' : 0;
            int bb = lb >= 0 ? b[lb] - '0' : 0;
            int sum = aa + bb + carry;
            carry = sum >= 2 ? 1: 0;
            sum = sum >= 2 ? sum - 2: sum;
            
            results.push_back('0' + sum);
            la -= 1;
            lb -= 1;
        }
        if (carry == 1)
            results.push_back('1');
        reverse(results.begin(), results.end());
        return results;
    }
};

int main(void)
{
    Solution sol = Solution();
    string results = sol.addBinary("101111", "10");
    cout << results << endl;
}