#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> result(triangle.back());
        int i = triangle.size() - 2;
        int j = 1;
        while (i >= 0)
        {
            j = 0;
            while (j < triangle[i].size())
            {
                if (result[j] > result[j + 1])
                {
                    result[j] = result[j + 1] + triangle[i][j];
                }
                else
                {
                    result[j] = result[j] + triangle[i][j];
                }
                j += 1;
            }
            i -= 1;
        }
        return result[0];
    }
};