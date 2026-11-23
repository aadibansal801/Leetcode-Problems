class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 1;
        while(j < n){
            if(j > 0 && nums[j] == nums[j-1]+1){
                count++;
            }else{
                count = 1;
            }
            if(j - i + 1 == k){
                if(count >= k){
                    ans.push_back(nums[j]);
                }else{
                    ans.push_back(-1);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};