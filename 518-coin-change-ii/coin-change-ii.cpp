class Solution {
public:

    vector<vector<long long>>dp;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long>prev(amount+1,0),curr(amount+1,0);
        for(int amnt = 0; amnt<=amount; amnt++){
            prev[amnt] = (amnt % coins[0] == 0);
        }
        for(int i = 1; i<n; i++){
            for(int amnt = 0; amnt<=amount; amnt++){
                long long notTake = prev[amnt];
                long long take = 0;
                if(coins[i]<=amnt){
                    take = curr[amnt-coins[i]];
                }
                long long sum = take + notTake;
                curr[amnt] = min(sum, (long long)2e9);
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};