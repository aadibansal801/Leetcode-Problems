class ExamTracker {
public:

    vector<int>times;
    vector<long long>scores;

    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        times.push_back(time);
        long long sum = score;
        if(!scores.empty()){
            sum += scores.back();
        }
        scores.push_back(sum);
    }

    long long totalScore(int startTime, int endTime) {
        int n = times.size();
        int left = 0, right = n;
        while(left < right){
            int mid = left + (right - left)/2;
            if(times[mid] >= startTime){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        int start = left;
        left = 0, right = n;
        while(left < right){
            int mid = left + (right - left)/2;
            if(times[mid] > endTime){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        int end = left;
        if(start == end) return 0;
        long long ans = scores[end-1];
        if(start > 0){
            ans -= scores[start-1];
        }
        return ans;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */