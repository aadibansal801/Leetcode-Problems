class Solution {
public:

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        const int INF = 10000;
        vector<int>next(sum+1, INF);
        vector<int>curr(sum+1, INF);
        next[0] = 0;
        for(int i = n-1; i>=0; i--){
            for(int s = 0; s<=sum; s++){
                curr[s] = next[s];
                if(nums[i]<=s){
                    curr[s] = min(curr[s], next[s-nums[i]]);
                }
                int bb = nums[i], op = 0;
                while(bb>0){
                    bb/=2; op++;
                    if(bb<=s){
                        curr[s] = min(curr[s], op + next[s-bb]);
                    }
                }
                bb = nums[i], op = 0;
                while(bb<=s){
                    bb*=2; op++;
                    if(bb<=s){
                        curr[s] = min(curr[s], op + next[s-bb]);
                    }
                }
            }
            next = curr;
        }
        return next[sum] >= INF ? -1 : next[sum];
    }
};