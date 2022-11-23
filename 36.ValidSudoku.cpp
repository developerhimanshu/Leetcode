//	https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidStep(vector<vector<char>>& board, int row, int col, char x){
        for(int i = 0; i<9; i++){
            if(board[i][col]==x)return false;
            if(board[row][i]==x)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==x)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]!='.'){
                    char x = board[i][j];
                    board[i][j]='.';
                    if(isValidStep(board, i, j, x)==false)return false;
                }
            }
        }
        return true;
    }
};