class Solution {
public:

    int loga(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        int res = 0;
        while(n>0){
            res++;
            n/=2;
        }
        return res;
    }

    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        for(int i = 0; i<n; i++){
            string s;
            int num = nums[i];
            while(num>0){
                int logi = loga(num);
                if(logi >= 27) s+='z';
                else s+=logi+97-1;
                int diff;
                if(logi >= 27) diff = (int)(pow(2,26-1));
                else diff = (int)(pow(2,logi-1));
                num = num - diff;
            }
            ans.push_back(s);
        }
        return ans;
    }
}; 