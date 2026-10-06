struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return ((uint64_t)p.first << 32) ^ (uint32_t)p.second;
    }
};

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<pair<int,int>,int, PairHash> cnt;
        int base = 0;
        for(int i = 0; i+1<nums.size(); i++){
            int a = nums[i];
            int b = nums[i+1];
            if(a==b){
                base++;
            }else{
                cnt[{a,b}]++;
                cnt[{b,a}]++;
            }
        }
        int best = 0;
        for(auto &[p, freq]: cnt){
            best = max(best, freq);
        }
        return base + best;
    }
};