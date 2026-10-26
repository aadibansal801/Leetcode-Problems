class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        int n = hand.size();
        sort(hand.begin(), hand.end());
        map<int,int> freq;
        for(int card: hand){
            freq[card]++;
        }
        for(auto [card, count]: freq){
            if(count == 0) continue;
            for(int i = 1; i<groupSize; i++){
                if(freq[card + i] < count){
                    return false;
                }
                freq[card + i] -= count;
            }
            freq[card] = 0;
        }
        return true;
    }
};

// []
// [[1,2,3], [2,3,4], [6,7,8]]
// {
//    1 -> 1
//    2 -> 2
//    3 -> 2
//    5 -> 1
//    6 -> 1
//    7 -> 1
//    8 -> 1
// }