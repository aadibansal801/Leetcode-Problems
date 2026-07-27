class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int minEnd = nums[0], maxEnd = nums[0];
        int minSum = nums[0], maxSum = nums[0];
        for(int i = 1; i<n; i++){
            maxEnd = max(nums[i], maxEnd + nums[i]);
            maxSum = max(maxSum, maxEnd);
            minEnd = min(nums[i], minEnd + nums[i]);
            minSum = min(minSum, minEnd);
        }
        return max(maxSum, -minSum);
    }
};