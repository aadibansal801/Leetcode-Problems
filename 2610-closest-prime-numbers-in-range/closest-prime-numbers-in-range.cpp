class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes;
        for(int i = left; i<=right; i++){
            if(isPrime(i)){
                primes.push_back(i);
            }
        }
        if(primes.size() < 2) return {-1,-1};
        int mini = INT_MAX;
        vector<int>ans(2);
        for(int i = 1; i<primes.size(); i++){
            int diff = primes[i] - primes[i-1];
            if(diff < mini){
                mini = diff;
                ans = {primes[i-1], primes[i]};
            }
        }
        return ans;
    }
    bool isPrime(int n){
        if(n<2) return false;
        for(int i = 2; i*i <=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
};