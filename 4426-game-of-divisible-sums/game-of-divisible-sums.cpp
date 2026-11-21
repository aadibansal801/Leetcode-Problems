class Solution {
public:

    vector<vector<long long>>dp;

    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return solve(0, 0, nums);
    }

    long long solve(int i, int turn, vector<int>&nums){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][turn]!=-1) return dp[i][turn];
        long long pick1 = LLONG_MIN, pick2 = LLONG_MIN;
        pick1 = nums[i];
        if(nums[i]%3){
            pick1 += solve(i+1, 0, nums);
        }else{
            pick1 += solve(i+1, 1, nums);
        }
        if(i + 1 < nums.size()){
            pick2 = nums[i] + nums[i+1];
            if(pick2 % 3){
                pick2 += solve(i+2, 0, nums);
            }else{
                pick2 += solve(i+2, 1, nums);
            }
        }
        int sign;
        if(turn){
            sign = -1;
        }else{
            sign = 1;
        }
        return dp[i][turn] = sign * max(pick1, pick2);
    }
};