class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int currMin = nums[i];
            int currAnd = nums[i];
            for(int j = i; j<n; j++){
                currAnd = currAnd & nums[j];
                currMin = min(currMin, nums[j]);
                if(currMin == currAnd) cnt++;
            }
        }
        return cnt;
    }
};