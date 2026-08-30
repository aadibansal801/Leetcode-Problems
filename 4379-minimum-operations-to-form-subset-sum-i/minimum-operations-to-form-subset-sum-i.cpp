class Solution {
public:

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        const int INF = 10000;
        vector<vector<int>>dp(n+1,vector<int>(sum+1, INF));
        dp[n][0] = 0;//base case
        for(int i = n-1; i>=0; i--){
            for(int s = 0; s<=sum; s++){
                dp[i][s] = dp[i+1][s];
                if(nums[i]<=s){
                    dp[i][s] = min(dp[i][s], dp[i+1][s-nums[i]]);
                }
                int bb = nums[i], op = 0;
                while(bb>0){
                    bb/=2; op++;
                    if(bb<=s){
                        dp[i][s] = min(dp[i][s], op + dp[i+1][s-bb]);
                    }
                }
                bb = nums[i], op = 0;
                while(bb<=s){
                    bb*=2; op++;
                    if(bb<=s){
                        dp[i][s] = min(dp[i][s], op+ dp[i+1][s-bb]);
                    }
                }
            }
        }
        return dp[0][sum] >= INF ? -1 : dp[0][sum];
    }
};