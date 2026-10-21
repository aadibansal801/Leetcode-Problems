class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>revGraph(n);
        vector<int>inDegree(n,0);
        for(int u = 0; u<n; u++){
            for(int v: graph[u]){
                revGraph[v].push_back(u);
                inDegree[u]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(int prev: revGraph[node]){
                inDegree[prev]--;
                if(inDegree[prev] == 0){
                    q.push(prev);
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};