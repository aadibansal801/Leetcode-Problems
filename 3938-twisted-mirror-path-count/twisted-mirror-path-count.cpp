class Solution {
public:

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> next(n,vector<int>(2,0));
        vector<vector<int>> curr(n,vector<int>(2,0));
        for(int r = m-1; r>=0; r--){
            for(int c = n-1; c>=0; c--){
                if(r == m-1 && c == n-1){
                    curr[c][0] = 1;
                    curr[c][1] = 1;
                    continue;
                }
                if(grid[r][c] == 1){
                    curr[c][0] = next[c][1];
                    curr[c][1] = (c+1<n)?curr[c+1][0]:0;
                }else{
                    int down = next[c][1];
                    int right = (c+1<n)?curr[c+1][0]:0;
                    curr[c][0] = (down + right)%MOD;
                    curr[c][1] = (down + right)%MOD;
                }
            }
            next = curr;
            curr.assign(n,vector<int>(2,0));
        }
        return next[0][0];
    }
};