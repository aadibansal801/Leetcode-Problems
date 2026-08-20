class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9+7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> powers(n+1,1);
        for(int i = 1; i<=n; i++){
            powers[i] = (powers[i-1]*2) % MOD;
        }
        int i = 0;
        int j = n-1;
        long long ans = 0;
        while(i<=j){
            if(nums[i] + nums[j] <= target){
                ans = (ans + powers[j-i])%MOD;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};