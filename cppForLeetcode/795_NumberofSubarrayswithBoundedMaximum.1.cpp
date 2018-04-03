#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int i = 0;
        int count = 0;
        int left = -1;
        int right = -1;
        for (i = 0; i < A.size(); ++i)
        {
            if (A[i] > R) left = i;
            if (A[i] >= L) right = i;
            count += right - left;
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