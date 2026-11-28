class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1;
        vector<vector<int>>adj(n);
        for(auto e: connections){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int nc = 0;
        for(int i = 0; i<n; i++){
            if(vis[i]) continue;
            nc++;
            queue<int>q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int nei: adj[node]){
                    if(!vis[nei]){
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        return nc-1;
    }
};
