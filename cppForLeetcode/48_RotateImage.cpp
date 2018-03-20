#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = i + 1; j < matrix[0].size(); ++j)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            start = 0;
            end = matrix[i].size() - 1;
            while(start < end)
            {
                temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start += 1;
                end -=1;
            }
        }
    }
};