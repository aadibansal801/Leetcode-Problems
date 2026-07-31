class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candid1,candid2;
        int vote1=0,vote2=0;
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(candid1 == nums[i]){
                vote1++;
            }else if(candid2 == nums[i]){
                vote2++;
            }else if(vote1 == 0){
                candid1 = nums[i];
                vote1 = 1;
            }else if(vote2 == 0){
                candid2 = nums[i];
                vote2 = 1;
            }else{
                vote1--;
                vote2--;
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto it: nums){
            if(it == candid1) cnt1++;
            if(it == candid2) cnt2++;
        }
        if(cnt1>n/3) ans.push_back(candid1);
        if(cnt2>n/3) ans.push_back(candid2);
        return ans;
    }
};