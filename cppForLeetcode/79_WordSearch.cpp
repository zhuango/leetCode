#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        table = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (bt(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool bt(vector<vector<char>>& board, int row, int col, string & word, int charIndex)
    {
        if (charIndex > word.size() - 1)
        {
            return true;
        }
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || table[row][col])
        {
            return false;
        }
        if (board[row][col] == word[charIndex])
        {
            table[row][col] = true;
            bool result = bt(board, row + 1, col, word, charIndex + 1) || 
                   bt(board, row, col + 1, word, charIndex + 1) ||
                   bt(board, row - 1, col, word, charIndex + 1) ||
                   bt(board, row, col - 1, word, charIndex + 1);
            table[row][col] = false;
            return result;
        }
        else
        {
            return false;
        }
    }
    private:
    vector<vector<bool>> table;
};

int main(void)
{
    vector<vector<char>> chars {{'A'}};
    Solution sol;
    cout << sol.exist(chars, "A") << endl;
    return 0;
}