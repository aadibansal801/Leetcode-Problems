class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int n = nums.size();
        vector<int>ans;
        while(l<n){
            int r = l;
            while(r<n && nums[r] == nums[l]){
                r++;
            }
            int count = r-l;
            if(count>n/3){
                ans.push_back(nums[l]);
            }
            l = r;
        }
        return ans;
    }
};