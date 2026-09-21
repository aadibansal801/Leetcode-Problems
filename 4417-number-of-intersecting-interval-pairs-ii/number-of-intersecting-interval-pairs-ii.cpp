class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        long long count = 0;
        priority_queue<int, vector<int>, greater<int>> ends;
        for(auto& interval: intervals){
            int start = interval[0];
            int end = interval[1];
            while(!ends.empty() && ends.top()<start){
                ends.pop();
            }
            count+=ends.size();
            ends.push(end);
        }
        return count;
    }
};