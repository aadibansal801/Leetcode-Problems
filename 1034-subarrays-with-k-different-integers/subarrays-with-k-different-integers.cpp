class Solution {
public:

    int atmost(vector<int>&nums, int k){
        if(k<0) return 0;
        int left = 0;
        int ans = 0;
        unordered_map<int,int> freq;
        int n = nums.size();
        int right = 0;
        while(right<n){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            ans+=(right - left + 1);
            right++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};