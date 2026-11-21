class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        int n = s1.size();
        int m = s2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            string a = "";
            string b = "";
            while(s1[i] != s2[j]){
                a+=s1[i];
                b+=s2[j];
                i++;
                j++;
            }
            i++;
            j++;
            if(!a.empty()){
                ans.push_back({a,b});
            }
        }
        return ans;
    }
};