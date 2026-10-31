class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<pair<int,int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}
        };
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = 1;
        int dist = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [r,c] = q.front();
                q.pop();
                if(r == n-1 && c == n-1) return dist;
                for(auto [dr, dc]: dirs){
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};