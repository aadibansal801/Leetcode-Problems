class Solution {
public:

    int solve(int sum, vector<int>&nums, int target, vector<int>&dp){
        if(sum == target){
            return 1;
        }
        if(sum > target){
            return 0;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ways = 0;
        for(int num: nums){
            ways += solve(sum + num, nums, target, dp);
        }
        return dp[sum] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(0, nums, target, dp);
    }
};