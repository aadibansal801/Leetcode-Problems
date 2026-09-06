class Solution {
public:

    int countScore(string s){
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i<n-1; i++){
            if(s[i] == s[i+1]){
                cnt++;
            }
        }
        return cnt;
    }

    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(countScore(s) == k){
                ans++;
            }
            s = s.substr(1) + s[0];
        }
        return ans;
    }
};