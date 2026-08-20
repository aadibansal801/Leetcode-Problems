class Solution {
public:

    void solve(int i, vector<int>&curr, vector<vector<int>>&ans, vector<int>&nums, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i == nums.size() || target<0){
            return;
        }
        for(int j = i; j<nums.size(); j++){
            if(j>i && nums[j]==nums[j-1]){
                continue;
            }
            if(nums[j]>target) break;
            curr.push_back(nums[j]);
            solve(j+1,curr,ans,nums,target-nums[j]);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,ans,candidates,target);
        return ans;
    }
};