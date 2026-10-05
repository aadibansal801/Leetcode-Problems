class Solution {
public:

    vector<vector<vector<vector<long long>>>> dp;

    long long solve(vector<int>&nums, int i, bool deleted, bool plus, bool started){
        if(i == nums.size()) return started ? 0 : LLONG_MIN;
        long long &res = dp[i][deleted][plus][started];
        if(res != LLONG_MIN) return res;
        res = LLONG_MIN;
        if(!started){
            res = solve(nums, i+1, deleted, plus, false);
        }
        int val = plus ? nums[i] : -nums[i];
        res = max(res, val + solve(nums, i+1, deleted, !plus, true));
        if(!deleted){
           res = max(res, solve(nums, i+1, true, plus, started));
        }
        if(started) res = max(res, 0LL);
        return res;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<vector<vector<long long>>>(2, vector<vector<long long>>(2, vector<long long>(2, LLONG_MIN))));
        return solve(nums, 0, false, true, false);
    }
};