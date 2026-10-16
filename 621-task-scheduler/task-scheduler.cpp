class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(auto ch : tasks){
            freq[ch-'A']++;
        }
        priority_queue<int>pq;
        for(auto it: freq){
            if(it > 0){
                pq.push(it);
            }
        }
        queue<pair<int,int>>cooldown;
        int time = 0;
        while(!pq.empty() || !cooldown.empty()){
            time++;
            if(!pq.empty()){
                int f = pq.top();
                pq.pop();
                f--;
                if(f>0){
                    cooldown.push({f,time+n});
                }
            }
            if(!cooldown.empty() && cooldown.front().second == time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;
    }
};