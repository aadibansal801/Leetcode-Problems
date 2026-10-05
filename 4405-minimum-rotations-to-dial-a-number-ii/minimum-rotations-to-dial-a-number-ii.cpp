class Solution {
public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b){
            int d = abs(a-b);
            return min(d, 10-d);
        };
        int total = dist(0,s[0]-'0');
        for(int i = 1; i<n; i++){
            total += dist(s[i-1] - '0', s[i] - '0');
        }
        int ans = total;
        ans = min(ans, total - dist(0, s[0] - '0') + dist(0, s[n-1]-'0'));
        for(int k = 1; k<n; k++){
            int oldEdge = dist(s[k-1]-'0', s[k]-'0');
            int newEdge = dist(s[k-1]-'0', s[n-1]-'0');
            ans = min(ans, total - oldEdge + newEdge);
        }
        return ans;
    }
};