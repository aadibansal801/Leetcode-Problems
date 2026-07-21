class Solution {
public:

    int expand(int i, int j, string &s){
        int n = s.size();
        int cnt = 0;
        while(i>=0 && j<n && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += expand(i,i,s);
            ans+=expand(i,i+1,s);
        }
        return ans;
    }
};