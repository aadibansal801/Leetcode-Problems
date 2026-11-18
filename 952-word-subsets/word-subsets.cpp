class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<string>ans;
        vector<int>required(26, 0);
        for(int i = 0; i<m; i++){
            vector<int>freq(26,0);
            for(int j = 0; j<words2[i].size(); j++){
                freq[words2[i][j] - 'a']++;
            }
            for(int j = 0; j<26; j++){
                required[j] = max(required[j], freq[j]);
            }
        }
        for(int i = 0; i<n; i++){
            vector<int>freq(26,0);
            for(int j = 0; j<words1[i].size(); j++){
                freq[words1[i][j] - 'a']++;
            }
            bool toInclude = true;
            for(int j = 0; j<26; j++){
                if(required[j]==0) continue;
                if(freq[j] < required[j]){
                    toInclude = false;
                    break;
                }
            }
            if(toInclude)ans.push_back(words1[i]);
        }
        return ans;
    }
};