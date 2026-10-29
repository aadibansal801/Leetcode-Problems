class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int>mp;
        int n = x.size();
        for(int i = 0; i<n; i++){
            if(mp.find(x[i])==mp.end()){
                mp[x[i]] = y[i];
            }else{
                mp[x[i]] = max(mp[x[i]], y[i]);
            }
        }
        if(mp.size() < 3) return -1;
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        for(auto &it: mp){
            long long val = it.second;
            if(val > first){
                third = second;
                second = first;
                first = val;
            }else if(val > second){
                third = second;
                second = val;
            }else if(val > third){
                third = val;
            }
        }
        return (int)(first + second + third);
    }
};