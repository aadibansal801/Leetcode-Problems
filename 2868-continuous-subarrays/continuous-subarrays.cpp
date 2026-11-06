class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        for(int r = 0; r<n; r++){
            mp[nums[r]]++;
            while(abs(mp.begin()->first - mp.rbegin()->first) > 2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans += r - i + 1;
        }
        return ans;
    }
};