class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = solve(-1, nums);
        for(int i = 0; i<n; i++){
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
    int solve(int idx, vector<int>&nums){
        vector<int>arr;
        arr.reserve(nums.size());
        for(int i = 0; i<nums.size(); i++){
            if(i!=idx){
                arr.push_back(nums[i]);
            }
        }
        int m = arr.size();
        vector<int>pref(m);
        vector<int>suff(m);
        pref[0] = arr[0];
        for(int i = 1; i<m; i++){
            pref[i] = gcd(pref[i-1],arr[i]);
        }
        suff[m-1] = arr[m-1];
        for(int i = m-2; i>=0; i--){
            suff[i] = gcd(suff[i+1],arr[i]);
        }
        int cnt = 0;
        for(int i = 0; i<m-1; i++){
            if(pref[i] == suff[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};