class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int count = 0;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j] = true;
                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();
                        for(int k = 0; k<4; k++){
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1'){
                                q.push({nr,nc});
                                vis[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};