class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i = 0; i<=n; i++){
            int it = i;
            int cnt = 0;
            while(it>1){
                if(it & 1) cnt+=1;
                it/=2;
            }
            if(it == 1) cnt+=1;
            ans.push_back(cnt);
        }
        return ans;
    }
};