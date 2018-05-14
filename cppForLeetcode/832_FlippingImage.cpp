#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        if(A.empty()) return vector<vector<int>>();
        vector<vector<int>> images (A.size(), vector<int>(A[0].size(), 0));
        int colSize = A[0].size() - 1;
        for(int i = 0; i < A.size(); ++i)
        {
            for(int j = 0; j < A[0].size(); ++j)
            {
                if(A[i][j] == 0)
                {
                    images[i][colSize - j] = 1;
                }
                else
                {
                    images[i][colSize - j] = 0;
                }
            }
        }
        return images;
    }
};