class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        def atMost(k):
            if k<0:
                return 0
            i = 0
            total = 0
            ans = 0
            for j in range(len(nums)):
                total+=nums[j]
                while total > k:
                    total-=nums[i]
                    i+=1
                ans+=j-i+1
            return ans
        return atMost(goal) - atMost(goal-1)