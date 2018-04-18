#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sum1;
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j =0; j < B.size(); ++j)
            {
                sum1[A[i] + B[j]] ++;
            }
        }
        int count = 0;
        for(int i = 0; i < C.size(); ++i)
        {
            for(int j =0; j < D.size(); ++j)
            {
                count += sum1[-1 * (C[i] + D[j])];
            }
        }
        return count;
    }
};