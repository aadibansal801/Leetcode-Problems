class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<bool>>knows(m+1, vector<bool>(n+1, false));
        for(int i = 0; i<m; i++){
            for(int lang: languages[i]){
                knows[i+1][lang] = true;
            }
        }
        unordered_set<int> needTeaching;
        for(auto f: friendships){
            int u = f[0];
            int v = f[1];
            bool canComm = false;
            for(int lang = 1; lang<=n; lang++){
                if(knows[u][lang] && knows[v][lang]){
                    canComm = true;
                    break;
                }
            }
            if(!canComm){
                needTeaching.insert(u);
                needTeaching.insert(v);
            }
        }
        int ans = needTeaching.size();
        for(int lang = 1; lang <= n; lang++){
            int cnt = 0;
            for(int user: needTeaching){
                if(!knows[user][lang]){
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};