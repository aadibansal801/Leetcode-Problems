class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>>q; //r,c,t
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        int time = 0;
        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};
        while(!q.empty()){
            auto [r,c,t] = q.front();
            q.pop();
            time = max(time, t);
            for(int k = 0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc < m && nc >= 0 && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    q.push({nr,nc,t+1});
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};