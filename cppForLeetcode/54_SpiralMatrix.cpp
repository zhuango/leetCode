#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rowEnd = matrix.size();
        int rowStart = 0;
        if (rowEnd == 0) return result;
        int colEnd = matrix[0].size();
        int colStart = 0;
        int i = 0;
        while(rowStart < rowEnd && colStart < colEnd)
        {
            if (colStart < colEnd)
            {
                for(i = colStart; i < colEnd; ++i)
                {
                    result.push_back(matrix[rowStart][i]);
                }
                rowStart += 1;
            }
            if(rowStart < rowEnd)
            {
                for (i = rowStart; i < rowEnd; ++i)
                {
                    result.push_back(matrix[i][colEnd - 1]);
                }
                colEnd -= 1;
            }
            if (colStart < colEnd)
            {
                for(i = colEnd - 1; i >= colStart; --i)
                {
                    result.push_back(matrix[rowEnd - 1][i]);
                }
                rowEnd -= 1;
            }
            if (rowStart < rowEnd)
            {
                for(i = rowEnd - 1; i >= rowStart; --i)
                {
                    result.push_back(matrix[i][colStart]);
                }
                colStart += 1;
            }
        }
        return result;
    }
};