class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0;
        int maxOnes = 0;
        for(int i = 0; i<mat.size(); i++){
            int cnt = accumulate(mat[i].begin(), mat[i].end(),0);
            if(cnt>maxOnes){
                maxOnes = cnt;
                row = i;
            }
        }
        return {row,maxOnes};
    }
};