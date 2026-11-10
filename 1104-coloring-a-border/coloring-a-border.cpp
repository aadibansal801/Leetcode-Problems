class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int originalColor = grid[row][col];
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col] = true;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int k = 0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == originalColor){
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]) continue;
                for(int k = 0; k<4; k++){
                    int nx = i + dr[k];
                    int ny = j + dc[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || !vis[nx][ny]){
                        grid[i][j] = color;
                        break;
                    }
                }
            }
        }
        return grid;
    }
};