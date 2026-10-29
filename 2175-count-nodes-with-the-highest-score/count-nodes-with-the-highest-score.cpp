class Solution {
public:

    vector<vector<int>>adj;
    vector<int>subSize;
    long long maxScore = 0;
    int ans = 0;
    int n;

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        adj.assign(n, {});
        subSize.assign(n, 0);
        for(int i = 1; i<n; i++){
            adj[parents[i]].push_back(i);
        }
        dfs(0);
        for(int node = 0; node < n; node++){
            long long score = 1;
            int remaining = n - subSize[node];
            if(remaining > 0){
                score*=remaining;
            }
            for(int child: adj[node]){
                score *= subSize[child];
            }
            if(score > maxScore){
                maxScore = score;
                ans = 1;
            }else if(score == maxScore){
                ans++;
            }
        }
        return ans;
    }
    int dfs(int node){
        subSize[node] = 1;
        for(int child: adj[node]){
            subSize[node] += dfs(child);
        }
        return subSize[node];
    }
};