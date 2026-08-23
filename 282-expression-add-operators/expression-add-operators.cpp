class Solution {
public:

    vector<string>ans;
    string s;
    long long target;

    vector<string> addOperators(string num, int target) {
        this->s = num;
        this->target = target;
        solve(0,"",0,0);
        return ans;
    }
    void solve(int i, string expr, long long value, long long prev){
        if (i == s.size()){
            if(value == target){
                ans.push_back(expr);
            }
            return;
        }
        long long curr = 0;
        for(int j = i; j<s.size(); j++){
            if(j>i && s[i] == '0'){
                break;
            }
            curr = curr * 10 + (s[j] - '0');
            string num = s.substr(i,j-i+1);
            if(i == 0){
                solve(j+1,num,curr,curr);
            }else{
                solve(j+1,expr + "+" + num, value + curr, curr);
                solve(j+1,expr + "-" + num, value - curr, -curr);
                solve(j+1,expr + "*" + num, value - prev + prev * curr, prev * curr);
            }
        }
    }
};