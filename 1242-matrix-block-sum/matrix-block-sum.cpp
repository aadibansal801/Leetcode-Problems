class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int sum = 0;
                for(int r = max(0,i-k); r<=min(m-1,i+k); r++){
                    for(int c = max(0,j-k); c<=min(n-1,j+k); c++){
                        sum+=mat[r][c];
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;
    }
};