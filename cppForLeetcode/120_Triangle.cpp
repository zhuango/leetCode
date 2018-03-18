#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum = triangle[0][0];
        int i = 1;
        int j = 1;
        int min = 0;
        int temp = 0;
        while (i < triangle.size())
        {
            triangle[i][0] += triangle[i -1][0];
            min = 0;
            j = 1;
            while (j < triangle[i].size() - 1)
            {
                temp = triangle[i][j];
                if (temp + triangle[i-1][j - 1] > temp + triangle[i-1][j])
                {
                    temp += triangle[i-1][j];
                }
                else
                {
                    temp += triangle[i-1][j - 1];
                }
                triangle[i][j] = temp;
                if (temp < triangle[i][min])
                {
                    min = j;
                }
                j += 1;
            }
            triangle[i][j] += triangle[i - 1][j - 1];
            if (triangle[i][j] < triangle[i][min])
            {
                min = j;
            }
            i += 1;
        }
        return triangle[i-1][min];
    }
};