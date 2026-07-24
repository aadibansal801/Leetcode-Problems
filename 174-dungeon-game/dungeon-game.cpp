class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>& dungeon){
        int n = dungeon.size();
        int m = dungeon[0].size();
        if(i>=n || j>=m) return INT_MAX;
        if(i == n-1 && j == m-1){
            return max(1, 1 - dungeon[i][j]);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i, j+1, dungeon);
        int down = solve(i+1, j, dungeon);
        int need = min(right,down) - dungeon[i][j];
        return dp[i][j] = max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        dp.assign(n+1, vector<int>(m,-1));
        return solve(0,0,dungeon);
    }
};