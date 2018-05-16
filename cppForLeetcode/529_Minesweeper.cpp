#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        if(board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1], visited);
        return board;
    }
    void dfs(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &visited)
    {
        if(row < 0 or row >= board.size() or col < 0 or col >= board[0].size() || visited[row][col])
        {
            return;
        }

        visited[row][col] = true;
        if(board[row][col] != 'E' && board[row][col] != 'B') return;

        if(board[row][col] == 'E')
        {
            boom(board, row, col);
            if(board[row][col] != 'B') return;
        }

        dfs(board, row + 1, col, visited);
        dfs(board, row + 1, col+1, visited);
        dfs(board, row + 1, col-1, visited);
        dfs(board, row - 1, col+1, visited);
        dfs(board, row - 1, col-1, visited);
        dfs(board, row - 1, col, visited);
        dfs(board, row, col+1, visited);
        dfs(board, row, col-1, visited);
    }
    void boom(vector<vector<char>> &board, int row, int col)
    {
        int rowM1 = max(row-1, 0);
        int rowA1 = min(row+1, int(board.size()-1));
        int colM1 = max(col-1, 0);
        int colA1 = min(col+1, int(board[0].size()-1));
        
        bool BrowM1 = row-1 >= 0;
        bool BrowA1 = row+1 <= board.size()-1;
        bool BcolM1 = col-1 >= 0;
        bool BcolA1 = col+1 <= board[0].size()-1;

        int mine =0;
        if(BrowA1) mine += board[rowA1][col]=='M' ? 1:0;
        if(BrowA1 && BcolA1)mine += board[rowA1][colA1]=='M' ? 1:0;
        if(BrowA1 && BcolM1)mine += board[rowA1][colM1]=='M' ? 1:0;
        if(BrowM1 && BcolA1)mine += board[rowM1][colA1]=='M' ? 1:0;
        if(BrowM1 && BcolM1)mine += board[rowM1][colM1]=='M' ? 1:0;
        if(BrowM1)mine += board[rowM1][col]=='M' ? 1:0;
        if(BcolA1)mine += board[row][colA1]=='M' ? 1:0;
        if(BcolM1)mine += board[row][colM1]=='M' ? 1:0;

        if(mine) board[row][col] = mine + '0';
        else board[row][col] = 'B';
    }
};
[["E","E","E","E","E","E","E","E"],
 ["E","E","E","E","E","E","E","M"],
 ["E","E","M","E","E","E","E","E"],
 ["M","E","E","E","E","E","E","E"],
 ["E","E","E","E","E","E","E","E"],
 ["E","E","E","E","E","E","E","E"],
 ["E","E","E","E","E","E","E","E"],
 ["E","E","M","M","E","E","E","E"]]