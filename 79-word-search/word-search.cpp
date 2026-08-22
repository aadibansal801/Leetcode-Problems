class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(solve(i,j,0,vis,board,word,n,m)){
                    return true;
                }
            }
        }
        return false;
    }
    bool solve(int i, int j, int len, vector<vector<bool>>&vis, vector<vector<char>>&board, string& word, int n, int m){
        if(len == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return false;
        if(board[i][j]!=word[len]) return false;
        vis[i][j] = true;
        bool found = solve(i+1,j,len+1,vis,board,word,n,m)||
                     solve(i,j+1,len+1,vis,board,word,n,m)||
                     solve(i-1,j,len+1,vis,board,word,n,m)||
                     solve(i,j-1,len+1,vis,board,word,n,m);
        vis[i][j] = false;
        return found;
    }
};