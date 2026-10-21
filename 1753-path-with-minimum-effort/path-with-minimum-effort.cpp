class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        dist[0][0] = 0;
        pq.push({0,0,0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int effort = node[0];
            int r = node[1];
            int c = node[2];
            if(effort > dist[r][c]) continue;
            if(r == n-1 && c == m-1){
                return effort;
            }
            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                    continue;
                }
                int edge = abs(heights[r][c] - heights[nr][nc]);
                int newEffort = max(effort, edge);
                if(newEffort < dist[nr][nc]){
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
        return 0;
    }
};