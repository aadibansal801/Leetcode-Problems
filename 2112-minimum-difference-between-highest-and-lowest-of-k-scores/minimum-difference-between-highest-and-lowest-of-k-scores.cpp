class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = k-1;
        int minDiff = INT_MAX;
        while(j < n){
            int diff = nums[j] - nums[i];
            minDiff = min(minDiff, diff);
            i++;
            j++;
        }
        return minDiff;
    }
};