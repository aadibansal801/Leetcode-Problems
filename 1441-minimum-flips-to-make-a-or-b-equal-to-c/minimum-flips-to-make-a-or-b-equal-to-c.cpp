class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while(a>0 || b>0 || c>0){
            int bit1 = a % 2;
            int bit2 = b % 2;
            int bit3 = c % 2;
            if(bit3 == 1){
                if(bit1 == 0 && bit2 == 0){
                    cnt+=1;
                }
            }else{
                cnt += bit1 + bit2;
            }
            a/=2;
            b/=2;
            c/=2;
        }
        return cnt;
    }
};