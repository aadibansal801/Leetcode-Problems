class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(i<s.length()  && s[i]==' '){
            i++;
        }

        bool neg = false;
        if(i < s.length() && s[i] == '-'){
            neg = true;
            i++;
        }
        else if(i < s.length() && s[i] == '+'){
            i++;
        }
        long long ans = 0;
        long long limit = neg ? 2147483648LL : 2147483647LL;
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
            int digit = s[i] - '0';
            if(ans > limit/10 || (ans == limit/10 && digit > limit%10)){
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return neg ? -ans : ans;
    }
};