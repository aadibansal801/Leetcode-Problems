class Solution {
public:

    void solve(int i, string curr, vector<string>&ans, int n, bool canInclude0){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        if(canInclude0){
            curr+='0';
            solve(i+1,curr,ans,n,false);
            curr.pop_back();
            curr+='1';
            solve(i+1,curr,ans,n,true);
            curr.pop_back();
        }else{
            curr+='1';
            solve(i+1,curr,ans,n,true);
            curr.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        vector<string>ans;
        string current;
        solve(0,current,ans,n,true);
        return ans;
    }
};