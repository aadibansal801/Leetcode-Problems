class Solution {
public:

    const int INF = 1e9;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>next(amount+1, INF);
        next[0] = 0;
        for(int i = n-1; i>=0; i--){
            for(int amnt = 1; amnt<=amount; amnt++){
                int skip = next[amnt];
                int take = INF;
                if(coins[i]<=amnt) take = 1 + next[amnt-coins[i]];
                next[amnt] = min(take, skip);
            }
        }
        int ans = next[amount];
        if(ans >= INF) return -1;
        return ans;
    }
};