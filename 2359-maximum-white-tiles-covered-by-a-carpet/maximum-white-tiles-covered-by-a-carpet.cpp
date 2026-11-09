class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        int i = 0, j = 0;
        long long sum = 0;
        long long ans = 0;
        while(i<n){
            int end = tiles[i][0] + carpetLen - 1;
            while(j < n && tiles[j][1] <= end){
                sum += tiles[j][1] - tiles[j][0] + 1;
                j++;
            }
            if(j<n && tiles[j][0] <= end){
                long long partial = end - tiles[j][0] + 1;
                ans = max(ans, sum + partial);
            }
            ans = max(sum, ans);
            sum -= tiles[i][1] - tiles[i][0] + 1;
            i++;
        }
        return ans;
    }
};