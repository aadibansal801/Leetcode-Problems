class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int components = 0;
        for(int i = 0; i<n; i++){
            if(visited[i]) continue;
            components++;
            queue<int>q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int j = 0; j<n; j++){
                    if(isConnected[node][j] == 1 && !visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return components;
    }
};