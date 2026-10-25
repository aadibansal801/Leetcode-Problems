class Solution {
public:
    int dp[101][101];

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s,0,0);
    }
    bool solve(string s, int i, int cnt){
        if(cnt<0) return false;
        if(i == s.size()){
            return cnt == 0;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        if(s[i] == '(') return dp[i][cnt] = solve(s,i+1,cnt+1);
        if(s[i] == ')') return dp[i][cnt] = solve(s,i+1,cnt-1);
        bool open = solve(s, i+1, cnt+1);
        bool close = solve(s, i+1, cnt-1);
        bool empty = solve(s, i+1, cnt);
        return dp[i][cnt] = open || close || empty;
    }
};