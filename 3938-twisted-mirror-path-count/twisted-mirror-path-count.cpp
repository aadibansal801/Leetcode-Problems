class Solution {
public:

    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>>dp;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n, vector<int>(2,0)));
        dp[m-1][n-1][0] = 1;
        dp[m-1][n-1][1] = 1;
        for(int r = m-1; r>=0; r--){
            for(int c = n-1; c>=0; c--){
                if(r == m-1 && c == n-1) continue;
                if(grid[r][c] == 1){
                    dp[r][c][0] = (r+1<m)?dp[r+1][c][1]:0;
                    dp[r][c][1] = (c+1<n)?dp[r][c+1][0]:0;
                }else{
                    int down = (r+1<m)?dp[r+1][c][1]:0;
                    int right = (c+1<n)?dp[r][c+1][0]:0;
                    dp[r][c][0] = (down + right)%MOD;
                    dp[r][c][1] = (down + right)%MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};