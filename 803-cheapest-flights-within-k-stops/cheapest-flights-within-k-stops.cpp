class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it: flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        queue<tuple<int,int,int>>q;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        q.push({src,0,0});
        while(!q.empty()){
            auto[node,cost,stops] = q.front();
            q.pop();
            if(stops>k) continue;
            for(auto &[nei,wt]: adj[node]){
                if(cost + wt < dist[nei]){
                    dist[nei] = cost + wt;
                    q.push({nei,cost+wt,stops+1});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};