class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;
        for(auto it: s){
            int num = it - '0';
            int dis = abs(curr - num);
            ans+=min(dis, 10-dis);
            curr = num;
        }
        return ans;
    }
};
