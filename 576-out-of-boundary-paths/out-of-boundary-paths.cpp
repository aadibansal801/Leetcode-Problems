class Solution {
public:
    const int mod = 1e9+7;
    int rows,cols;
    vector<vector<vector<int>>>dp;

    int solve(int i, int j, int movesLeft){
        if(i<0 || j< 0 || i>=rows || j>=cols) return 1;
        if(movesLeft == 0) return 0;
        if(dp[i][j][movesLeft]!=-1) return dp[i][j][movesLeft];
        long long ans = 0;
        ans = (ans + solve(i+1,j,movesLeft-1))%mod;
        ans = (ans + solve(i,j+1,movesLeft-1))%mod;
        ans = (ans + solve(i-1,j,movesLeft-1))%mod;
        ans = (ans + solve(i,j-1,movesLeft-1))%mod;

        return dp[i][j][movesLeft] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rows = m;
        cols = n;
        dp.assign(m,vector<vector<int>>(n,vector<int>(maxMove + 1,-1)));
        return solve(startRow, startColumn, maxMove);
    }
};