class Solution {
public:

    unordered_map<int,int>mp;
    vector<vector<int>>dp;

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n>1 && stones[1] != 1){
            return false;
        }
        for(int i = 0; i<n; i++){
            mp[stones[i]] = i;
        }
        dp.assign(n, vector<int>(n+1,0));
        dp[1][1] = 1;
        for(int i = 1; i<n; i++){
            for(int k = 1; k<=n; k++){
                if(!dp[i][k]) continue;
                for(int jump = k-1; jump<=k+1; jump++){
                    if(jump<=0) continue;
                    int target = stones[i] + jump;
                    if(mp.count(target)){
                        int next = mp[target];
                        dp[next][jump] = 1;
                    }
                }
            }
        }
        for(int k = 1; k<=n; k++){
            if(dp[n-1][k]) return true;
        }
        return false;
    }
};