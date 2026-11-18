class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<int>childCount(n,0);
        vector<long long>sum(n,0);
        vector<long long>mn(n, LLONG_MAX);
        vector<long long>dp(n,0);
        for(int i = 1; i<n; i++){
            childCount[parent[i]]++;
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(childCount[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            dp[node] = score[node];
            if(mn[node]!=LLONG_MAX){
                dp[node] += sum[node];
                if(op[node] == 1){
                    dp[node] -= mn[node];
                }else{
                    dp[node] -= min(0LL, mn[node]);
                }
            }
            if(node == 0) continue;
            int p = parent[node];
            sum[p] += dp[node];
            mn[p] = min(mn[p], dp[node]);
            childCount[p]--;
            if(childCount[p] == 0){
                q.push(p);
            }
        }
        return (int)dp[0];
    }
};

//task 1 -> identify the leaf nodes (whichever node that does not appear in parent is the leaf node)
//task 2 -> work your way from bottom to top 
//task 3 -> if op is 1, select the subtree with min score
//task 4 -> if op is 0, select the subtree with negative score, if no neg score do nothing
//task 5 -> return the score