class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==1){
                curr++;
            }
            ans = max(curr,ans);
            if(nums[i]==0){
                curr = 0;
            }
        }
        return ans;
    }
};