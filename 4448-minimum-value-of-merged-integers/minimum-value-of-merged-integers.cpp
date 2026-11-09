class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n-1; i+=2){
            int a = nums[i];
            int b = nums[i+1];
            long long factor = 10;
            while(b>=10){
                factor*=10;
                b/=10;
            }
            int number = a*factor+nums[i+1];
            ans = min(ans, number);
        }
        return ans;
    }
};