class Solution {
public:

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,s,curr,ans);
        return ans;
    }
    void solve(int i, string &s, vector<string>&curr, vector<vector<string>>&ans){
        if(i == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int end = i; end<s.size(); end++){
            if(isPalindrome(i,end,s)){
                curr.push_back(s.substr(i,end-i+1));
                solve(end+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(int i, int end, string &s){
        while(i<=end){
            if(s[i]!=s[end]){
                return false;
            }
            i++;
            end--;
        }
        return true;
    }
};