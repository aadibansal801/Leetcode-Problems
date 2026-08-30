class Solution {
public:

    int solve(int i, int sum, vector<int>&nums, vector<vector<int>>&dp){
        if(i == nums.size()){
            if(sum == 0){
                return 0;
            }else return 10000;
        }
        if(dp[i][sum]!=INT_MAX) return dp[i][sum];
        int op = 0, bb = nums[i];
        int ans = solve(i+1,sum,nums,dp);
        if(nums[i]<=sum){
            ans = min(ans, solve(i+1,sum - nums[i], nums, dp));
        }
        while(bb>0){
            bb/=2; op++;
            int cc = bb;
            if(cc == 0){
                break;
            }
            int op1 = op;
            while(cc<=sum){
                cc*=2; op1++;
                if(cc<=sum){
                    ans = min(ans, (op1 + solve(i+1, sum-cc, nums, dp)));
                }
            }
            if(bb<=sum){
                ans = min(ans, (op + solve(i+1,sum-bb,nums,dp)));
            }
        }
        bb = nums[i], op = 0;
        while(bb<=sum){
            bb *= 2; op++;
            if(bb<=sum){
                ans = min(ans, (op + solve(i+1, sum - bb, nums, dp)));
            }
        }
        return dp[i][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        int sumx = sum * 2;
        vector<vector<int>>dp(n,vector<int>(sumx+10, INT_MAX));
        int ans = solve(0,sum,nums,dp);
        if(ans >= 10000){
            return -1;
        }
        return ans;
    }
};
