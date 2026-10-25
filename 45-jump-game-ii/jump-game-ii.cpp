class Solution {
public:

    int solve(int idx, vector<int>&nums, vector<int>&dp){
        int n = nums.size();
        if(idx >= n - 1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int mini = INT_MAX;
        for(int i = 1; i<=nums[idx]; i++){
            if(idx + i < n){
                int jumps = solve(idx+i, nums, dp);
                if(jumps != INT_MAX){
                    mini = min(mini, jumps+1);
                }
            }
        }
        return dp[idx] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0,nums, dp);
    }
};