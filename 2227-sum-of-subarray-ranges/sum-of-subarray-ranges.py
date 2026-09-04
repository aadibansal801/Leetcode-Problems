class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(0,n):
            largest = nums[i]
            smallest = nums[i]
            for j in range(i+1,n):
                largest = max(largest,nums[j])
                smallest = min(smallest, nums[j])
                ans+=largest-smallest
        return ans