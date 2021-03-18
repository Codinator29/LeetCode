/*

https://leetcode.com/problems/surrounded-regions/

Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/

class Solution {
public:
    
    void expand(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) 
            return;
        if (board[i][j] == 'O') {
            board[i][j] = 'A';
            expand(board, i+1, j);
            expand(board, i-1, j);
            expand(board, i, j+1);
            expand(board, i, j-1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) 
            return;
        
        for (int i = 0; i < board.size(); ++i) {
            expand(board, i, 0);
            expand(board, i, board[0].size()-1);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            expand(board, 0, j);
            expand(board, board.size()-1, j);
        }
        
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                if (board[i][j] == 'A') 
                    board[i][j] = 'O';
        }
    }
};