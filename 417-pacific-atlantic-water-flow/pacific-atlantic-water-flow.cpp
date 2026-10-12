class Solution {
public:

    int m,n;
    vector<vector<int>>dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    void bfs(vector<vector<int>>& heights, vector<vector<int>>& vis, queue<pair<int,int>>q){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto d: dir){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nc < 0 || nr >=m || nc >= n) continue;
                if(vis[nr][nc]) continue;
                if(heights[nr][nc] < heights[r][c]) continue;
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->m = heights.size();
        this->n = heights[0].size();
        vector<vector<int>>pacific(m, vector<int>(n,0));
        vector<vector<int>>atlantic(m, vector<int>(n,0));
        queue<pair<int,int>>pq, aq;
        for(int r = 0; r<m; r++){
            pq.push({r,0});
            pacific[r][0] = 1;
        }
        for(int c = 0; c<n; c++){
            pq.push({0,c});
            pacific[0][c] = 1;
        }
        for(int r = 0; r<m; r++){
            aq.push({r,n-1});
            atlantic[r][n-1] = 1;
        }
        for(int c = 0; c<n; c++){
            aq.push({m-1,c});
            atlantic[m-1][c] = 1;
        }

        bfs(heights, pacific, pq);
        bfs(heights, atlantic, aq);

        vector<vector<int>>ans;

        for(int r = 0; r<m; r++){
            for(int c = 0; c<n; c++){
                if(pacific[r][c] && atlantic[r][c]){
                    ans.push_back({r,c});
                }
            }
        }
        return ans;
    }
};