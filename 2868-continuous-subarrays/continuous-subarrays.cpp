class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int>maxD, minD;
        int n = nums.size();
        int i = 0;
        long long ans = 0;
        for(int r = 0; r<n; r++){//n
            while(!maxD.empty() && nums[maxD.back()]<nums[r]){ //1
                maxD.pop_back();
            }
            maxD.push_back(r);
            while(!minD.empty() && nums[minD.back()]>nums[r]){//1
                minD.pop_back();
            }
            minD.push_back(r);
            while(nums[maxD.front()] - nums[minD.front()] > 2){
                if(maxD.front() == i) maxD.pop_front();
                if(minD.front() == i) minD.pop_front();
                i++;
            }
            ans += r - i + 1;
        }
        return ans;
    }
};