#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty()) return M;
        int m = M.size();
        int n = M[0].size();
        int rowMin;
        int rowMax;
        int colMin;
        int colMax;
        int tempColMin;
        int sum = 0;
        int count = 0;
        vector<vector<int>> results(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                rowMin = max(0, i - 1);
                rowMax = min(m, i + 2);
                colMin = max(0, j - 1);
                colMax = min(n, j + 2);
                count = 0;
                sum = 0;
                while(rowMin < rowMax)
                {
                    tempColMin = colMin;
                    while(tempColMin < colMax)
                    {
                        sum += M[rowMin][tempColMin];
                        count += 1;
                        tempColMin += 1;
                    }
                    rowMin += 1;
                }
                results[i][j] = sum / count;
            }
        }
        return results;
    }
};