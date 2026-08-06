class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<vector<int>>>dp;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(maxMove+1,vector<vector<int>>(m,vector<int>(n,0)));
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
                            ways++;
                        }else{
                            ways+=dp[moves-1][nr][nc];
                        }
                    }
                    ways%=mod;
                    dp[moves][i][j] = ways;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};