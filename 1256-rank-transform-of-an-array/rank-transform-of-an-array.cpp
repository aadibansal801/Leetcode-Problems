class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>rank;
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end());
        int r = 1;
        for(int it: sorted){
            if(!rank.count(it)){
                rank[it] = r;
                r++;
            }
        }
        vector<int>ans;
        for(auto it: arr){
            ans.push_back(rank[it]);
        }
        return ans;
    }
};