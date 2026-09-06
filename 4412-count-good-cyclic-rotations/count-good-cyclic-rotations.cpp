class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        long long left = 0;
        for(int it: nums){
            total+=it;
        }
        for(int i = 0; i<n/2; i++){
            left+=nums[i];
        }
        int ans = 0;
        for(int k = 0; k<n; k++){
            if(2*left>total){
                ans++;
            }
            left-=nums[k];
            left+=nums[(k+n/2)%n];
        }
        return ans;
    }
};