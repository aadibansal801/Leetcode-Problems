class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0, b = 1, c = 1;
        while(a + b + c < n){
            long long next = b + c;
            a = b;
            b = c;
            c = next;
        }
        return a + b + c == n;
    }
};