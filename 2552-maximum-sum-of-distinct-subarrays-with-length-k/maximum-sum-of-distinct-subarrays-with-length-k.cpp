class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long cursum = 0;
        long long  maxsum = 0;
        int i = 0;
        unordered_map<int,int>freq;
        for(int j = 0; j<n; j++){
            cursum+=nums[j];
            freq[nums[j]]++;
            if(j-i+1>k){
                cursum-=nums[i];
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            if(j-i+1 == k && freq.size() == k){
                maxsum = max(maxsum, cursum);
            }
        }
        return maxsum;
    }
};