#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;
        bool hasZero = false;
        for(int i = 0; i < matrix.size(); ++i)
        {
            hasZero = false;
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    hasZero = true;
                }
            }
            if (hasZero) rows.push_back(i);
        }
        for(int i = 0; i < matrix[0].size(); ++i)
        {
            hasZero = false;
            for (int j = 0; j < matrix.size(); ++j)
            {
                if (matrix[j][i] == 0)
                {
                    hasZero = true;
                }
            }
            if (hasZero) cols.push_back(i);
        }
        for(int i : rows)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                matrix[i][j] = 0;
            }
        }
        for(int i : cols)
        {
            for(int j = 0; j < matrix.size(); ++j)
            {
                matrix[j][i] = 0;
            }
        }
    }
};