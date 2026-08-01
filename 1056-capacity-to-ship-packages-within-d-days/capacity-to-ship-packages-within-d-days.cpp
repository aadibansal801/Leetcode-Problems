class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canShip(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    bool canShip(vector<int>& weights, int days, int mid){
        int requiredDays = 1;
        int load = 0;
        for(int weight: weights){
            if(load + weight <= mid){
                load+=weight;
            }else{
                requiredDays++;
                load = weight;
            }
        }
        return requiredDays<=days;
    }
};