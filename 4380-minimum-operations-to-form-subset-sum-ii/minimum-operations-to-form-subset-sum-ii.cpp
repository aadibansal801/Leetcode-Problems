class Solution {
public:

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        const int INF = 10000;
        vector<int>curr(sum+1,INF);
        vector<int>next(sum+1,INF);
        next[0] = 0;
        for(int i = n-1; i>=0; i--){
            for(int s = 0; s<=sum; s++){
                int ans = next[s];
                if(nums[i]<=s){
                    ans = min(ans, next[s-nums[i]]);
                }
                int bb = nums[i];
                int op = 0;
                while(bb>0){
                    bb/=2; op++;
                    int cc = bb;
                    if(cc == 0){
                        break;
                    }
                    int op1 = op;
                    while(cc <= s){
                        cc*=2, op1++;
                        if(cc<=s){
                            ans = min(ans, op1 + next[s-cc]);
                        }
                    }
                    if(bb<=s){
                        ans = min(ans, op + next[s-bb]);
                    }
                }
                bb = nums[i];
                op = 0;
                while(bb<=s){
                    bb*=2; op++;
                    if(bb<=s){
                        ans = min(ans, op + next[s-bb]);
                    }
                }
                curr[s] = ans;
            }
            next = curr;
        }
        return next[sum] >= INF ? -1 : next[sum];
    }
};
