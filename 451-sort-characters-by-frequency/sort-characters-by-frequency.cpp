class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>map;
        for(auto it: s){
            map[it]++;
        }
        vector<vector<char>>bucket(n+1);
        for(auto &[ch,cnt]: map){
            bucket[cnt].push_back(ch);
        }
        string ans = "";
        for(int i = n; i>=1; i--){
            for(auto ch: bucket[i]){
                ans+=string(i,ch);
            }
        }
        return ans;
    }
};