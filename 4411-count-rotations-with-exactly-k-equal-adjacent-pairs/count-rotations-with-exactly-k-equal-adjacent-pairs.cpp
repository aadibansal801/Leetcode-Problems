class Solution {
public:

    int countRotations(string s, int k) {
        int ans = 0;
        int n = s.size();
        int total = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == s[(i+1) % n]){
                total++;
            }
        }
        for(int i = 0; i<n; i++){
            int score = total - (s[(i-1+n)%n] == s[i]);
            if(score == k) ans++;
        }
        return ans;
    }
};