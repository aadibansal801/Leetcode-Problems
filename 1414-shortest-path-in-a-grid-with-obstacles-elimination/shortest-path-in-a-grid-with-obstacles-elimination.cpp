class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int,int,int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,-1));
        q.push({0,0,k,0});
        vis[0][0] = k;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto [r,c,rem,steps] = q.front();
            q.pop();
            if(r == n-1 && c == m-1){
                return steps;
            }
            for(int k = 0; k<4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m)
                    continue;
                int newRem = rem - grid[nr][nc];
                if(newRem < 0) continue;
                if(vis[nr][nc] >= newRem) continue;
                vis[nr][nc] = newRem;
                q.push({nr, nc, newRem, steps + 1});
            }
        }
        return -1;
    }
};