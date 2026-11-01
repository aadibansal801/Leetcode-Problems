class Solution {
public:

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> next(n,vector<int>(2,0));
        for(int r = m-1; r>=0; r--){
            for(int c = n-1; c>=0; c--){
                if(r == m-1 && c == n-1){
                    next[c][0] = 1;
                    next[c][1] = 1;
                    continue;
                }
                int down = next[c][1];
                int right = (c+1<n)?next[c+1][0]:0;
                int ways = 0;
                if(grid[r][c] == 1){
                    next[c][0] = down;
                    next[c][1] = right;
                }else{
                    ways = (down + right) % MOD;
                    next[c][0] = ways;
                    next[c][1] = ways;
                }
            }
        }
        return next[0][0];
    }
};