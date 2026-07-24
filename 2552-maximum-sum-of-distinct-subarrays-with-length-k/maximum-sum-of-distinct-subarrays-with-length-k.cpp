class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int j = 0;
        int i = 0;
        unordered_map<int,int> freq;
        while(j<n){
            sum+=nums[j];
            freq[nums[j]]++;
            if(j-i+1 > k){
                sum-=nums[i];
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            if(j-i+1 == k && freq.size() == k){
                ans = max(ans, sum);
            }
            j++;
        }
        return ans;
    }
};