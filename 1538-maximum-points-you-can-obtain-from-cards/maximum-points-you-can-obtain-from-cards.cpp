class Solution {
public:

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k==n){
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }
        int size = n-k;
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int sum = 0;
        for(int i = 0; i<size; i++){
            sum+=cardPoints[i];
        }
        int minSum = sum;
        int start = 0;
        for(int end = size; end<n; end++){
            sum+=cardPoints[end];
            sum-=cardPoints[start];
            start++;
            minSum = min(minSum, sum);
        }
        return total - minSum;
    }
};