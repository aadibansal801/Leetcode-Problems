class Solution {
public:

    const int INF = 1e9;
    vector<vector<int>>dp;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,INF));
        for(int i = 0; i<=n; i++){
            dp[i][0] = 0;
        }
        for(int i = n-1; i>=0; i--){
            for(int amnt = 1; amnt<=amount; amnt++){
                int skip = dp[i+1][amnt];
                int take = INF;
                if(coins[i]<=amnt) take = 1 + dp[i][amnt-coins[i]];
                dp[i][amnt] = min(take, skip);
            }
        }
        int ans = dp[0][amount];
        if(ans >= INF) return -1;
        return ans;
    }
};