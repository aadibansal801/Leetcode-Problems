class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7 
        def power(x,n):
            if n==0:
                return 1
            a = power(x,n//2)
            if n%2==0:
                return (a*a) % MOD
            else:
                return (x*a*a) % MOD
        even = (n+1)//2
        odd = n//2
        return (power(5,even) * power(4,odd)) % MOD