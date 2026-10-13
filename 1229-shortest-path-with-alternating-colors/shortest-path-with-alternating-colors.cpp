class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e: redEdges){
            adj[e[0]].push_back({e[1], 0}); //red color = 0;
        }
        for(auto &e: blueEdges){
            adj[e[0]].push_back({e[1], 1}); //blue color = 1;
        }
        queue<array<int,3>>q; //{node, expected color, dist};
        vector<vector<bool>>vis(n, vector<bool>(2, false));
        vis[0][1] = vis[0][0] = true;
        vector<int>ans(n,-1);
        ans[0] = 0;
        q.push({0,0,0});
        q.push({0,1,0});
        while(!q.empty()){
            auto [node, color, dist] = q.front();
            q.pop();
            if(ans[node]==-1){
                ans[node] = dist;
            }
            for(auto [next, edgeColor]: adj[node]){
                if(edgeColor != color || vis[next][1-color]){
                    continue;
                }
                vis[next][1-color] = true;
                q.push({next, 1-color, dist + 1});
            }
        }
        return ans;
    }
};