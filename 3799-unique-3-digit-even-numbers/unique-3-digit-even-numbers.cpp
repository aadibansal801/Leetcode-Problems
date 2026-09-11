class Solution {
public:

    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<bool>visited(digits.size(),false);
        function<void(int)> solve = [&](int pos){
            if(pos == 3){
                ans++;
                return;
            }
            set<int>seen;
            for(int i = 0; i<digits.size(); i++){
                if(visited[i]) continue;
                if(seen.count(digits[i])) continue;
                if(pos == 0 && digits[i] == 0) continue; 
                if(pos == 2 && digits[i] % 2 != 0) continue;
                seen.insert(digits[i]);
                visited[i] = true;
                solve(pos+1);
                visited[i] = false;
            }
        };
        solve(0);
        return ans;
    }
};