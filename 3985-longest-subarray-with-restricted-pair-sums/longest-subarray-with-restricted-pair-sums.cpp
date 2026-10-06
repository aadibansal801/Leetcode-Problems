class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        unordered_map<int,int>freq;
        int l = 0;
        int ans = 0;
        for(int r = 0; r<nums.size(); r++){
            int x = nums[r];
            while(!valid(freq,x)){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            freq[x]++;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
    bool valid(unordered_map<int, int>freq, int x){
        for(auto &[a, count]: freq){
            if(freq.count(x+a)){
                return false;
            }
            int b = x-a;
            if(b > 0 && freq.count(b)){
                if(a!=b || count>=2){
                    return false;
                }
            }
        }
        return true;
    }
};