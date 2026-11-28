class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        int k = indices.size();

        vector<int> replace(n,-1);

        for(int i = 0; i<k; i++){
            int idx = indices[i];
            if(s.substr(idx, sources[i].size()) == sources[i]){
                replace[idx] = i;
            }
        }

        string ans = "";
        int i = 0;

        while(i<n){
            if(replace[i]!=-1){
                int j = replace[i];
                ans += targets[j];
                i += sources[j].size();
            }else{
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};