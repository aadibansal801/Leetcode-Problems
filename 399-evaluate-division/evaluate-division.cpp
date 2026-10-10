class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i= 0; i<(int)equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0/values[i]});
        }
        vector<double>ans;
        for(auto q: queries){
            ans.push_back(bfs(graph, q[0], q[1]));
        }
        return ans;
    }
    double bfs(unordered_map<string, vector<pair<string, double>>> &graph, string src, string dst){
        if(!graph.count(src) || !graph.count(dst)) return -1.0;
        if(src == dst) return 1.0;
        unordered_set<string>vis{src};
        queue<pair<string, double>>q;
        q.push({src, 1.0});
        while(!q.empty()){
            auto [node, prod] = q.front();
            q.pop();
            for(auto [next, w]: graph[node]){
                if(vis.count(next)) continue;
                if(next == dst) return prod * w;
                vis.insert(next);
                q.push({next, prod*w});
            }
        }
        return -1.0;
    }
};