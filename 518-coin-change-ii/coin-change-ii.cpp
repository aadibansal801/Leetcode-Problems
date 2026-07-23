class Solution {
public:

    vector<vector<long long>>dp;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n,vector<long long>(amount+1, 0));
        for(int amnt = 0; amnt<=amount; amnt++){
            dp[0][amnt] = (amnt % coins[0] == 0);
        }
        for(int i = 1; i<n; i++){
            for(int amnt = 0; amnt<=amount; amnt++){
                long long notTake = dp[i-1][amnt];
                long long take = 0;
                if(coins[i]<=amnt){
                    take = dp[i][amnt-coins[i]];
                }
                long long sum = take + notTake;
                dp[i][amnt] = min(sum, (long long)2e9);
            }
        }
        return (int)dp[n-1][amount];
    }
};