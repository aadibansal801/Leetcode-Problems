class Solution {
public:
    const int mod = 1e9+7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>>prev(m,vector<int>(n,0)); //dp[moves-1]
        vector<vector<int>>curr(m,vector<int>(n,0)); //dp[moves]
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        for(int moves = 1; moves<=maxMove; moves++){
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    long long ways = 0;
                    for(int k = 0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr<0||nr>=m||nc<0||nc>=n){
                            ways = (ways+1)%mod;
                        }else{
                            ways = (ways + prev[nr][nc])%mod;
                        }
                    }
                    curr[i][j] = ways;
                }
            }
            prev=curr;
        }
        return prev[startRow][startColumn];
    }
};