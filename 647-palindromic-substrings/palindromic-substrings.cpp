class Solution {
public:

    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            ans+=solve(i,i,s);
            ans+=solve(i,i+1,s);
        }
        return ans;
    }
    int solve(int i, int j, const string& s){
        int n = s.size();
        int cnt = 0;
        while(i>=0 && j<n && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
};