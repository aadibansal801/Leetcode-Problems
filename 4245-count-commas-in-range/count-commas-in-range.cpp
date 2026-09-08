class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        int num = n;
        while(num>0){
            num/=10;
            cnt++;
        }
        if(cnt<4) return 0;
        int ans = 0;
        for(int i = 1000; i<=n; i++){
            num = i;
            while(num>=1000){
                num/=1000;
                ans++;
            }
        }
        return ans;
    }
};