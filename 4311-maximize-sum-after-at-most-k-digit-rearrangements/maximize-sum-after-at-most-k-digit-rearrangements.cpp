class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int num: nums){
            sum+=num;
            string s = to_string(num);
            sort(s.begin(), s.end(), greater<char>());
            int rearranged = stoi(s);
            int gain = rearranged - num;
            if(pq.size() < k){
                pq.push(gain);
            }else if( k > 0 && gain > pq.top()){
                pq.pop();
                pq.push(gain);
            }
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};