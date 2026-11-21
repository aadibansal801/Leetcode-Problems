class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int idx = n-1;
        while(idx > 0 && target[idx-1] >= target[idx]){
            idx--;
        }
        unordered_map<int, int>diff;
        int valid = 0;
        auto update = [&](int val, int delta){
            if(diff[val] == 0) valid++;
            diff[val]+=delta;
            if(diff[val] == 0) valid--;
        };
        for(int i = 0; i<n; i++){
            update(nums[i],1);
            update(target[i], -1);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(i>=idx && valid == 0){
                ans++;
            }
            if(nums[i]!=target[i]){
                break;
            }
            update(nums[i],-1);
            update(target[i],1);
        }
        return ans;
    }
};