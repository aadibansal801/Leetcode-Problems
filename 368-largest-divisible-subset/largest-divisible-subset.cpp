class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        vector<int>ans;
        build(0,-1,nums,ans,dp);
        return ans;
    }
    void build(int i, int prev, vector<int>&nums, vector<int>&ans, vector<vector<int>>&dp){
        int n = nums.size();
        if(i == n) return;
        int skip = solve(i+1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[i]%nums[prev]==0){
            take = 1 + solve(i+1, i, nums, dp);
        }
        if(take >= skip && take > 0){
            ans.push_back(nums[i]);
            build(i+1, i, nums, ans, dp);
        }else{
            build(i+1, prev, nums, ans, dp);
        }
    }
    int solve(int i, int prev, vector<int>&nums, vector<vector<int>>&dp){
        int n = nums.size();
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int skip = solve(i+1, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[i]%nums[prev]==0){
            take = 1 + solve(i+1, i, nums, dp);
        }
        return dp[i][prev+1] = max(skip, take);
    }
};