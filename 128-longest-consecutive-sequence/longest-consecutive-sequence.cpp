class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it: nums){
            st.insert(it);
        }
        int maxlen = 0;
        for(auto num : st){
            int len = 1;
            if(!st.count(num-1)){
                int curr = num;
                while(st.count(curr+1)){
                    curr++;
                    len++;
                }
            }
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};