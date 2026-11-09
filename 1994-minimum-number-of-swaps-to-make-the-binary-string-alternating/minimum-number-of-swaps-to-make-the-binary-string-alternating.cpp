class Solution {
public:
    int minSwaps(string s) {
        int zeros = 0;
        int ones = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s[i] == '0') zeros++;
            else ones++;
        }
        if(abs(zeros - ones)>1) return -1;
        string s1 = "", s2 = "";
        for(int i = 0; i<n; i++){
            if(i%2==0){
                s1+='0';
                s2+='1';
            }else{
                s1+='1';
                s2+='0';
            }
        }
        int c1 = 0, c2 = 0;
        if(zeros == ones){
            for(int i = 0; i<n; i++){
                if(s[i]!=s1[i]) c1++;
                if(s[i]!=s2[i]) c2++;
            }
            return min(c1/2, c2/2);
        }
        if(ones > zeros){
            s1 = s2;
        }
        for(int i = 0; i<n; i++){
            if(s[i]!=s1[i]) c1++;
        }
        return c1/2;
    }
};