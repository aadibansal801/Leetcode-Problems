class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int depth = 0;
        for(auto it: s){
            if(it=='('){
                depth++;
                maxdepth = max(maxdepth,depth);
            }
            if(it==')'){
                depth--;
            }
        }
        return maxdepth;
    }
};