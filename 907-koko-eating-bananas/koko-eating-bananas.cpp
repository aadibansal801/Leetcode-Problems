class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low<=high){
            int mid = low + (high - low) /2;
            if(canFinish(piles, h, mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

    bool canFinish(vector<int>&piles, int hours, long long speed){
        long long timeNeeded = 0;
        for(int pile: piles){
            timeNeeded += (pile + speed -1) / speed;
        }
        return timeNeeded <= hours;
    }
};