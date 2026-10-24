class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int removals = 0;
        int lastEnd = intervals[0][1];
        int n = intervals.size();
        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= lastEnd){
                lastEnd = intervals[i][1];
            }else{
                removals++;
            }
        }
        return removals;
    }
};