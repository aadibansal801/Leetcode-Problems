class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefix(n+1,0);
        for(int i = 0; i<n; i++){
            int val = (i%2==0)?nums[i]:-nums[i];
            prefix[i+1] = prefix[i]+val;
        }
        long long original = prefix[n];
        long long maxPrefix[2] = {
            prefix[0],
            LLONG_MIN
        };
        long long bestDelta = 0;
        for(int r = 1; r<n; r++){
            int k = (r+1)%2;
            if(maxPrefix[k] != LLONG_MIN){
                long long delta = 2 * (maxPrefix[k] - prefix[r+1]);
                bestDelta = max(delta, bestDelta);
            }
            int p = r%2;
            maxPrefix[p]  = max(maxPrefix[p], prefix[r]);
        }
        return original + bestDelta;
    }
};
