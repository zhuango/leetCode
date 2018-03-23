#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) return nums;
        if (nums.size() * nums[0].size() != r * c ||
            (nums.size() == r && nums[0].size() == c)) return nums;
        vector<vector<int>> results(r, vector<int>(c, 0));
        int ii = 0;
        int jj = 0;
        int m = nums.size();
        int n = nums[0].size();
        for(int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                results[i][j] = nums[ii][jj];
                jj = (jj + 1) % n;
                if (jj == 0) ii = (ii + 1) % m;
            }
        }
        return results;
    }
};