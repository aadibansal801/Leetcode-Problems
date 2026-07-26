class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int s) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        int prefix = 0;
        for(int i = 0; i<n; i++){
            prefix += nums[i];
            int rem = prefix%s;
            if(mp.count(rem)){
                if(i - mp[rem] >=2){
                    return true;
                }
            }else{
                mp[rem] = i;
            }
        }
        return false;
    }
};