class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        const int MOD = 1e9 + 7;
        vector<int>gap(n);
        long long sum = 0;
        for(int i = 0; i<n; i++){
            gap[i] = abs(nums1[i] - nums2[i]);
            sum +=gap[i];
        }
        vector<int> sortedNums = nums1;
        sort(sortedNums.begin(), sortedNums.end());
        int maxReduction = 0;
        for(int i = 0; i<n; i++){
            auto it = lower_bound(sortedNums.begin(), sortedNums.end(), nums2[i]);
            if(it != sortedNums.end()){
                int newGap = abs(*it - nums2[i]);
                maxReduction = max(maxReduction, gap[i] - newGap);
            }
            if(it!=sortedNums.begin()){
                it--;
                int newGap = abs(*it - nums2[i]);
                maxReduction = max(maxReduction, gap[i] - newGap);
            }
        }
        return (sum - maxReduction) % MOD;
    }
};