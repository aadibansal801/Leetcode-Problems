class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans = mp.size();
        for(auto it: mp){
            if(it.second.size() < 3){
                ans--;
                continue;
            }
            vector<int>indices = it.second;
            int diff = indices[1] - indices[0];
            for(int i = 0; i<indices.size()-1; i++){
                if(indices[i+1]-indices[i]!=diff){
                    ans--;
                    continue;
                }
            }
        }
        if(ans<0) return 0;
        return ans;
    }
};