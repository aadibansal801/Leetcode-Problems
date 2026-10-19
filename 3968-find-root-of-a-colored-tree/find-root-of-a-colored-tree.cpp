class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int>inDegree(n,0);
        vector<int>outDegree(n,0);
        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            if(colors[u] == colors[v]){
                return -1;
            }
            if((colors[u] == 'R' && colors[v] == 'B') ||
               (colors[u] == 'B' && colors[v] == 'W') ||
               (colors[u] == 'W' && colors[v] == 'R')){
                outDegree[u]++;
                inDegree[v]++;
            }else{
                outDegree[v]++;
                inDegree[u]++;
            }
        }
        int root = -1;
        for(int i = 0; i < n; i++){
            if(outDegree[i] > 2 || inDegree[i]>1){
                return -1;
            }
            if(inDegree[i] == 0){
                if(root != -1) return -1;
                root = i;
            }
        }
        return root;
    }
};