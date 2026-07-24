class Solution {
public:

    vector<vector<int>>dp;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<int>next(m,0);
        next[m-1] = max(1, 1-dungeon[n-1][m-1]);
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                if(i == n-1 && j == m-1) {
                    continue;
                }
                int right,down;
                if(j+1<m) right = next[j+1];
                else right = INT_MAX;
                if(i+1<n) down = next[j];
                else down = INT_MAX;
                int need = min(right,down) - dungeon[i][j];
                next[j] = max(1, need);
            }
        }
        return next[0];
    }
};