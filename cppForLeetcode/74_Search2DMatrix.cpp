#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }
        int start = 0;
        int start2 = 0;
        int end = matrix.size() -1;
        int middle;
        int curElem;
        while (start <= end)
        {
            middle = start + (end - start) / 2;
            curElem = matrix[middle][0];
            if (curElem == target)
            {
                return true;
            }
            if (curElem < target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        if (start == 0) return false;
        start --;
        start2 = 0;
        end = matrix[0].size() -1;
        while (start2 <= end)
        {
            middle = start2 + (end - start2) / 2;
            curElem = matrix[start][middle];
            if (curElem == target)
            {
                return true;
            }
            if (curElem < target)
            {
                start2 = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        return false;
    }
};

int main(void)
{
    vector<vector<int>> input;
    Solution sol;
    cout << "DDDDDDDDDDDDDDDDDDDDDDDDDD" << endl;
    cout << sol.searchMatrix(input, 1) << endl;
}