class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(0,n):
            largest = float('-inf')
            smallest = float('inf')
            for j in range(i,n):
                largest = max(largest,nums[j])
                smallest = min(smallest, nums[j])
                ans+=largest-smallest
        return ans