#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> results;
        int temp = 1;
        int end = 1 + k;
        int tail = end + 1;
        bool flag = true;
        for(int i = k; i >= 0; --i)
        {
            if(flag)
            {
                flag = false;
                results.push_back(temp);
                temp += 1;
            }
            else
            {
                flag = true;
                results.push_back(end);
                end -= 1;
            }
        }
        for (int i = tail; i <= n; ++i)
        {
            results.push_back(i);
        }
        return results;
    }
};