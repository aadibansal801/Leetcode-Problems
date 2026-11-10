class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
        int n = capacity.size();
        vector<int>need(n);
        for(int i = 0; i<n; i++){
            need[i] = capacity[i] - rocks[i];
        }
        sort(need.begin(), need.end());
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(extra >= need[i]){
                extra-=need[i];
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }
};