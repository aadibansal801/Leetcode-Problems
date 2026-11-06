class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long ans = 0;
        while(j<n){
            if(nums[j]!=0){
                long long len = j - i;
                ans += len * (len + 1)/2;
                i = j+1;
            }
            j++;
        }
        long long len = n-i;
        ans += len * (len + 1)/2;
        return ans;
    }
};