class Solution {
public:

    vector<vector<long long>>dp;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1,vector<long long>(amount+1, 0));
        dp[n][0] = 1;
        for(int i = n-1; i>=0; i--){
            for(int amnt = 0; amnt<=amount; amnt++){
                long long take = 0;
                if(coins[i]<=amnt){
                    take = dp.at(i).at(amnt-coins[i]);
                }
                long long notTake = dp.at(i+1).at(amnt);
                long long sum = take + notTake;
                dp[i][amnt] = min(sum, (long long)2e9);
            }
        }
        return (int)dp[0][amount];
    }
};