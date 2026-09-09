class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int minSum = INT_MAX;
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int sum = 0;
        int start = 0;
        int end;
        for(end = 0; end<n-k; end++){
            sum+=cardPoints[end];
        }
        minSum = min(minSum, sum);
        while(end<n){
            sum+=cardPoints[end];
            sum-=cardPoints[start];
            start++;
            end++;
            minSum = min(sum, minSum);
        }
        return total - minSum;
    }
};