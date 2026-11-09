class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i<n-1; i+=2){
            string num1 = to_string(nums[i]);
            string num2 = to_string(nums[i+1]);
            int number = 0;
            int j = 0;
            while(j<num1.size()){
                int digit = num1[j]-'0';
                number = number*10 + digit;
                j++;
            }
            j = 0;
            while(j<num2.size()){
                int digit = num2[j]-'0';
                number = number*10 + digit;
                j++;
            }
            ans = min(ans, number);
        }
        return ans;
    }
};