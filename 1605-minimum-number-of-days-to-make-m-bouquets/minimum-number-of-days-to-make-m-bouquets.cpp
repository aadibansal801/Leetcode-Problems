class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL * m * k;
        if(total>bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canMake(bloomDay,m,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    bool canMake(vector<int>&nums, int m, int k, int day){
        int bouq = 0;
        int cnt = 0;
        for(int it: nums){
            if(it<=day){
                cnt++;
                if(cnt==k){
                    bouq++;
                    cnt = 0;
                }
            }else{
                cnt = 0;
            }
        }
        return bouq>=m;
    }
};