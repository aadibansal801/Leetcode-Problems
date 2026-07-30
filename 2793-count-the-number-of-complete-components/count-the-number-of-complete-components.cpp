class DSU{
public:
    vector<int> par;
    vector<int> size;
    DSU(int n){
        par.resize(n+1);
        size.assign(n+1,1);
        for(int i=0; i<=n; i++){
            par[i] = i;
        }
    }
    int findPar(int node){
        if(node == par[node]) return node;
        return par[node] = findPar(par[node]);
    }
    void unionBySize(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv) return;
        if(size[pu]>size[pv]){
            par[pv] = pu;
            size[pu]+=size[pv];
        }else{
            par[pu] = pv;
            size[pv]+=size[pu];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        for(auto e: edges){
            ds.unionBySize(e[0], e[1]);
        }
        unordered_map<int,int> nodes;
        unordered_map<int,int> edgeCount;
        for(int i = 0; i<n; i++){
            nodes[ds.findPar(i)]++;
        }
        for(auto e: edges){
            edgeCount[ds.findPar(e[0])]++;
        }
        int ans = 0;
        for(auto &[par, cnt] : nodes){
            if(edgeCount[par] == cnt * (cnt-1)/2){
                ans++;
            }
        }
        return ans;
    }
};