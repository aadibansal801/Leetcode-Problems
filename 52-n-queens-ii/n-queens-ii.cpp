class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(0,board,n);
        return ans;
    }
    void solve(int col, vector<string>&board, int n){
        if(col == n){
            ans++;
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(col,row,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,n);
                board[row][col] = '.';
            }
        }
    }
    bool isSafe(int col, int row, vector<string>&board, int n){
        for(int r = 0; r<col; r++){
            if(board[row][r] == 'Q') return false;
        }
        for(int r = row - 1, c = col - 1; r>=0 && c>=0; r--,c--){
            if(board[r][c] == 'Q') return false;
        }
        for(int r = row + 1, c = col - 1; r<n && c>=0; r++, c--){
            if(board[r][c] == 'Q') return false;
        }
        return true;
    }
};