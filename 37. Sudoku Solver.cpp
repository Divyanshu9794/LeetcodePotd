class Solution {
private:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch ){
        for( int i = 0; i < 9; i++ ){
            if( board[i][col] == ch && i != row ){
                return false;
            }
            if( board[row][i] == ch && i != col ){
                return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if( (board[3*(row/3) + i%3][3*(col/3) + j%3] == ch) && (3*(row/3) + i%3 != row) && (3*(col/3) + j%3 != col )){
                return false;
            }
            }
        }
        return true;
    }
    bool solve( vector<vector<char>>& board ){
        for( int i = 0; i < board.size(); i++ ){
            for( int j = 0; j < board.size(); j++ ){
                if( board[i][j] == '.' ){
                    for( char ch = '1'; ch <= '9'; ch++ ){
                        if( isSafe(board,i,j,ch) ){
                            
                            board[i][j] = ch;
                            if( solve(board) == true ){
                                return true;
                            }
                           
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
