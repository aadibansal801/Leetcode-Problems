class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        map<int, int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        while(!mp.empty()){
            vector<int>remove;
            for(auto &[x,f]: mp){
                ans.push_back(x);
                f--;
                if(f==0){
                    remove.push_back(x);
                }
            }
            for(auto it: remove){
                mp.erase(it);
            }
        }
        return ans;
    }
};