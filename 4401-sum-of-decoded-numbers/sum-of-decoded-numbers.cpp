class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long x, long long y) {
        long long ans = 1;

        while (y > 0) {
            if (y & 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;

        for (auto it : nums) {
            int width = it % 10;

            string d = to_string(it / 10);

            string x = d.substr(0, width);
            string y = d.substr(width);

            long long xi = stoll(x);
            long long yi = stoll(y);

            ans = (ans + modPow(xi, yi)) % MOD;
        }

        return ans;
    }
};