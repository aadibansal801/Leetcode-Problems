class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto &e: edges){ //O(E)
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int ans = -1;
        int minCount = INT_MAX;

        for(int src = 0; src<n; src++){ //O(N)
            vector<int>dist(n, INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            dist[src] = 0;
            pq.push({0,src});

            while(!pq.empty()){ //O((N+E))logN)
                auto[d, node] = pq.top();
                pq.pop();
                if(d>dist[node])continue;
                for(auto [nei, wt]: adj[node]){
                    if(d + wt < dist[nei]){
                        dist[nei] = d + wt;
                        pq.push({dist[nei], nei});
                    }
                }
            }

            int cnt = 0;
            for(int i = 0; i<n; i++){ //O(N)
                if(i!=src && dist[i] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= minCount){
                minCount = cnt;
                ans = src;
            }
        }
        return ans;
    }
};