class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && k > 0 && (st.top() > num[i])){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){ //edge case for strictly increasing numbers
            st.pop();
            k--;
        }
        if(st.empty()) return "0"; //edge case
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back() == '0'){ //edge case for leading 0s
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};