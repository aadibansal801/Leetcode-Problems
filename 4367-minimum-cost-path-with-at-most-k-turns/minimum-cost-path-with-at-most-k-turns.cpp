class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int INF = 1e9;
        vector<vector<vector<vector<int>>>>dist(
            m,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    5,
                    vector<int>(k+1, INF)
                )
            )
        );
        using state = tuple<int, int, int, int, int>;
        priority_queue<state, vector<state>, greater<state>>pq;
        dist[0][0][4][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0, 4, 0});
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while(!pq.empty()){
            auto [cost, r, c, prevDir, turns] = pq.top();
            pq.pop();
            if(cost != dist[r][c][prevDir][turns]){
                continue;
            }
            if(r == m-1 && c == n-1){
                return cost;
            }
            for(int dir = 0; dir<4; dir++){
                int nr = r+dr[dir];
                int nc = c+dc[dir];
                if(nr<0 || nr>=m || nc<0 || nc>=n){
                    continue;
                }
                int newTurns = turns;
                if(prevDir != 4 && prevDir != dir){
                    newTurns++;
                }
                if(newTurns > k){
                    continue;
                }
                int newCost = cost + grid[nr][nc];
                if(newCost < dist[nr][nc][dir][newTurns]){
                    dist[nr][nc][dir][newTurns] = newCost;
                    pq.push({newCost, nr, nc, dir, newTurns});
                }
            }
        }
        return -1;
    }
};