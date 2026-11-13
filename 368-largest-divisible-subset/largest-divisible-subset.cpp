class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int prev = i-1; prev >= -1; prev--){
                int skip = dp[i+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[i]%nums[prev] == 0){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][prev+1] = max(take, skip);
            }
        }
        vector<int>ans;
        int prev = -1;
        for(int i = 0; i<n; i++){
            int skip = dp[i+1][prev+1];
            int take = 0;
            if(prev == -1 || nums[i]%nums[prev]==0){
                take = 1 + dp[i+1][i+1];
            }
            if(take >= skip && take > 0){
                ans.push_back(nums[i]);
                prev = i;
            }
        }
        return ans;
    }
};