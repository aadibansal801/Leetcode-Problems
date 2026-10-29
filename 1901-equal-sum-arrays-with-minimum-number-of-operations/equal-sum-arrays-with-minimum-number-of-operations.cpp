class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > 6*m || m > 6*n) return -1;
        int sum1 = 0, sum2 = 0;
        for (int x : nums1) sum1 += x;
        for (int x : nums2) sum2 += x;
        if (sum1 == sum2) return 0;
        if (sum1 > sum2){
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        vector<int> changes;
        for(int it: nums1){
            changes.push_back(6-it);
        }
        for(int it: nums2){
            changes.push_back(it-1);
        }
        sort(changes.begin(), changes.end(), greater<int>());
        int diff = sum2 - sum1;
        int ans = 0;
        for(int change: changes){
            diff-=change;
            ans++;
            if(diff <= 0){
                return ans;
            }
        }
        return -1;
    }
};