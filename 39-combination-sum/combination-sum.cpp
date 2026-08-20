class Solution {
public:

    void solve(int i, vector<int>&curr, vector<vector<int>>&ans, vector<int>&nums, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i == nums.size()){
            return;
        }
        if(nums[i]<=target){
            curr.push_back(nums[i]);
            solve(i,curr,ans,nums,target-nums[i]);
            curr.pop_back();
        }
        solve(i+1,curr,ans,nums,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,curr,ans,candidates,target);
        return ans;
    }
};