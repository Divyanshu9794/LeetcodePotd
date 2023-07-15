class Solution {
public:
    void helper(int i,int j,vector<vector<char>>& board,int n,int m,vector<vector<bool>>& vis){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j] != 'O')
            return;
        
        vis[i][j] = true;
        board[i][j] = '1';
        helper(i+1,j,board,n,m,vis);
        helper(i-1,j,board,n,m,vis);
        helper(i,j+1,board,n,m,vis);
        helper(i,j-1,board,n,m,vis);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O')
                helper(0,j,board,n,m,vis);
            if(board[n-1][j] == 'O')
                helper(n-1,j,board,n,m,vis);
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                helper(i,0,board,n,m,vis);
            if(board[i][m-1] == 'O')
                helper(i,m-1,board,n,m,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
