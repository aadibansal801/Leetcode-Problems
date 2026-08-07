class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>s_map;
        unordered_map<char,int>t_map;
        for(int i = 0; i<s.size(); i++){
            char a = s[i];
            char b = t[i];

            if(s_map.count(a) && s_map[a]!=b){
                return false;
            }
            if(t_map.count(b) && t_map[b]!=a){
                return false;
            }
            s_map[a] = b;
            t_map[b] = a;
        }
        return true;
    }
};