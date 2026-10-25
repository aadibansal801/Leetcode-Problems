class Solution {
public:

    bool checkValidString(string s) {
        int l = 0;
        int r = 0;
        for(char c: s){
            if(c == '('){
                l++;
                r++;
            }else if(c == ')'){
                l--;
                r--;
            }else{
                l--;
                r++;
            }
            if(r<0) return false;
            l = max(l,0);
        }
        return l == 0;
    }
};