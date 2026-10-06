class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(source.size()==1){
            return source == target;
        }
        long long s1 = 0, s2 = 0;
        for(auto it: source) s1+=it;
        for(auto it: target) s2+=it;
        return s1==s2;
    }
};