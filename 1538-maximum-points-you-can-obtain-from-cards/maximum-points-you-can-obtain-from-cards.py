class Solution:
    def maxScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        total = sum(nums)
        if k==n:
            return total
        size = n-k
        windSum = 0
        for i in range(size):
            windSum += nums[i]
        minSum = windSum
        start = 0
        for end in range(size, n):
            windSum+=nums[end]
            windSum-=nums[start]
            start+=1
            minSum = min(minSum, windSum)
        return total - minSum