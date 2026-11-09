class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int it: nums){
            k+=it;
        }
        int cnt = 0;
        for(int i = 0; i<k; i++){
            cnt+=nums[i];
        }
        int maxi = cnt;
        for(int i = k; i<n+k; i++){
            cnt+=nums[i%n];
            cnt-=nums[(i-k)%n];
            maxi = max(cnt, maxi);
        }
        return k - maxi;
    }
};