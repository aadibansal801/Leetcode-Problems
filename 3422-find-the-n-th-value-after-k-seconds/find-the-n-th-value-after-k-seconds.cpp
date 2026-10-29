class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<long long>a(n,1);
        while(k--){
            for(int i = 1; i<n; i++){
                a[i] = (a[i-1] + a[i]) % MOD;
            }
        }
        return a[n-1] % MOD;
    }
};