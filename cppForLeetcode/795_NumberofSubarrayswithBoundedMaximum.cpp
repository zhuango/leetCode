#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int length = 0;
        int i = 0;
        int count = 0;
        int temp = 0;
        vector<int> table(A.size(), -1);
        for (length = 0; length < A.size(); ++length)
        {
            for(i = 0; i < A.size() - length; ++i)
            {
                temp = A[i + length];
                if (temp > table[i])
                {
                    table[i] = temp;
                }
                if (table[i] >= L && table[i] <= R) count += 1;
                if (temp > R) i += length;
            }
        }
        return count;
    }
};

int main(void)
{
    Solution sol;
    vector<int> input = {1,7,0,0,9,3,0,7};
    cout << sol.numSubarrayBoundedMax(input, 7, 8) << endl;
}