#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        int count = 0;
        int rowStart = 0;
        int rowEnd = 0;
        int colStart = 0;
        int colEnd = 0;
        int tempColStart = 0;
        for(int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                count = 0 - (board[i][j]&1);
                rowStart = max(0, i - 1);
                rowEnd = min(i + 1, m - 1);
                colStart = max(0, j - 1);
                colEnd = min(j + 1, n - 1);
                while(rowStart <= rowEnd)
                {
                    tempColStart = colStart;
                    while(tempColStart <= colEnd)
                    {
                        count += board[rowStart][tempColStart] & 1;
                        tempColStart += 1;
                    }
                    rowStart += 1;
                }
                if ((board[i][j] & 1) == 1 && count > 1 && count < 4)
                {
                    board[i][j] |= 2;
                }
                if ((board[i][j] & 1) == 0 && count == 3)
                {
                    board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                board[i][j] >>= 1;
            }
        }
    }
};