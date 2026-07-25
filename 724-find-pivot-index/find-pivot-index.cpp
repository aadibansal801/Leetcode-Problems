class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftsum = 0;
        for(int i = 0; i<n; i++){
            if(leftsum == total - leftsum - nums[i]){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};