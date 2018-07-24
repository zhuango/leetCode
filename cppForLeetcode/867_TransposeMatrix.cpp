#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()) return vector<vector<int>>();
        vector<vector<int>> results(A[0].size(), vector<int>(A.size(), 0));
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < A[0].size(); ++j)
            {
                results[j][i] = A[i][j];
            }
        }
        return results;
    }
};