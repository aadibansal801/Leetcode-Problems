class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>ans;
        solve(1,k,n,curr,ans,0);
        return ans;
    }
    void solve(int i, int k, int n, vector<int>&curr, vector<vector<int>>&ans, int sum){
        if(curr.size() == k){
            if(sum == n){
                ans.push_back(curr);
            }
            return;
        }
        if(i>9) return;
        curr.push_back(i);
        solve(i+1,k,n,curr,ans,sum+i);
        curr.pop_back();
        solve(i+1,k,n,curr,ans,sum);
    }
};