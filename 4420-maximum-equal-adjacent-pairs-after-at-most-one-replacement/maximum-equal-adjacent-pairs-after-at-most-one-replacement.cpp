class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int> cnt;
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