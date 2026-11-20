class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> occupied;
        for(int i = 0; i<n; i++){
            if(seats[i] == 1){
                occupied.push_back(i);
            }
        }
        int m = occupied.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(seats[i] == 1) continue;
            int low = 0, high = m-1;
            int right = m;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(occupied[mid] >= i){
                    right = mid;
                    high = mid-1;
                }else{
                    low = mid + 1;
                }
            }
            int minDist = INT_MAX;
            if(right < m){
                minDist = min(minDist, occupied[right]-i);
            }
            if(right > 0){
                minDist = min(minDist, i - occupied[right-1]);
            }
            ans = max(ans, minDist);
        }
        return ans;
    }
};