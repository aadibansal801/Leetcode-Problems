class Solution:
    def countGoodRotations(self, nums: list[int]) -> int:
        n = len(nums)
        total = sum(nums)
        l = 0
        r = n//2-1
        left = sum(nums[l:r+1])
        ans = 0
        for _ in range(n):
            if(2*left>total):
                ans+=1
            left-=nums[l]
            l = (l+1)%n
            r = (r+1)%n
            left+=nums[r]
        return ans