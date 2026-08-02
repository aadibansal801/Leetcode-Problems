class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = low + (high - low)/2;
            if(isValid(nums,k,mid)){
                high = mid-1;
            }else{ 
                low = mid+1;
            }
        }
        return low;
    }
    bool isValid(vector<int>&nums, int k, int mid){ 
        int sum = 0;
        int count = 1;
        for(auto it: nums){
            if(sum + it > mid){
                count++;
                sum = it;
            }else{
                sum+=it;
            }
        }
        return count<=k;
    }
};