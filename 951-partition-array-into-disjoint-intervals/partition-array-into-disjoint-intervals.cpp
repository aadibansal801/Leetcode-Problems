class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>rightMin(n); // 1 1
        rightMin[n-1] = nums[n-1]; 
        for(int i = n-2; i>=0; i--){
            rightMin[i] = min(rightMin[i+1], nums[i]);
        }
        int leftMax = nums[0]; //1
        for(int i = 0; i<n-1; i++){
            leftMax = max(leftMax, nums[i]);
            if(leftMax<=rightMin[i+1]){
                return i+1;
            }
        }
        return -1;
    }
};