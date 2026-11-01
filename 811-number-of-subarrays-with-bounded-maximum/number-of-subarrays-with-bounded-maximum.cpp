class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int count = 0;
        int ans = 0;
        int window = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]>right){
                window = 0;
                count = 0;
            }else{
                window++;
                if(nums[i] >= left){
                    count = window;
                }
            }
            ans+=count;
        }
        return ans;
    }
};