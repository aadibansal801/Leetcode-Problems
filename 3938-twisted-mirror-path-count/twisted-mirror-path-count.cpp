class Solution {
public:

    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>>dp;

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n, vector<int>(2,-1)));
        return solve(0,0,0,grid);
    }

    int solve(int r, int c, int dir, vector<vector<int>>&grid){
        if(r>=m || c>=n) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c][dir]!=-1) return dp[r][c][dir];
        int ways = 0;
        if(grid[r][c] == 1){
            if(dir == 0){
                ways = (ways + solve(r+1,c,1,grid)) % MOD;
            }else{
                ways = (ways + solve(r,c+1,0,grid)) % MOD;
            }
        }else{
            ways = (ways + solve(r+1,c,1,grid)) % MOD;
            ways = (ways + solve(r,c+1,0,grid)) % MOD;
        }
        return dp[r][c][dir] = ways % MOD;
    }
};