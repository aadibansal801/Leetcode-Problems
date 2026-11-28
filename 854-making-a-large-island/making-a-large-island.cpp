class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        int node = i * n + j;
                        int nei = nr * n + nc;
                        ds.unionBySize(node, nei);
                    }
                }
            }
        }
        int mx = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                set<int>components;
                for(int k = 0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if(grid[nr][nc] == 1){
                            int nei = ds.findUPar(nr * n + nc);
                            components.insert(nei);
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for(int i = 0; i<n*n; i++){
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};