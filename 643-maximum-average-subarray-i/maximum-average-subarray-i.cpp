class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<k; i++){
            sum+=nums[i];
        }
        int maxSum = sum;
        int start = 0;
        int end = k;
        while(end<n){
            sum+=nums[end];
            sum-=nums[start];
            maxSum = max(maxSum, sum);
            end++;
            start++;
        }
        return (double)maxSum/k;
    }
};