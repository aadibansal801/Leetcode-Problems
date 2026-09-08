class Solution:
    def numberOfSubarrays(self, nums: List[int], n: int) -> int:
        def atMost(k):
            if k<0:
                return 0
            i = 0
            odd = 0
            ans = 0
            for j in range(len(nums)):
                odd+=nums[j]%2
                while odd > k:
                    odd-=nums[i]%2
                    i+=1
                ans += j - i + 1
            return ans
        return atMost(n) - atMost(n-1)