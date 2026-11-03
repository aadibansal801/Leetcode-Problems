class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int cnt = -1;
        bool flag = true;
        for(auto it: nums){
            if(it!=0){
                flag = false;
            }
        }
        if(flag) return 0;
        int low = 0, high = m-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums,mid,queries)){
                cnt = mid+1;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return cnt;
    }
    bool isPossible(vector<int>&nums, int mid, vector<vector<int>>&queries){
        int n = nums.size();
        vector<int>diff(n+1,0);
        for(int i = 0; i<=mid; i++){
            auto a = queries[i];
            diff[a[0]]+=a[2];
            diff[a[1]+1]-=a[2];
        }
        int prev = 0;
        for(int i = 0; i<n; i++){
            prev+=diff[i];
            if(nums[i]>prev) return false;
        }
        return true;
    }
};