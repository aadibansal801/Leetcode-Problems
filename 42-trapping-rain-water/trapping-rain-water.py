class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        pref = [-1] * n
        suff = [-1] * n
        pref[0] = height[0]
        for i in range(1, n):
            pref[i] = max(pref[i-1], height[i])
        suff[n-1] = height[n-1]
        for i in range(n-2,-1,-1):
            suff[i] = max(suff[i+1], height[i])
        total = 0
        for i in range(0,n):
            if pref[i] > height[i] and suff[i] > height[i]:
                total += min(pref[i], suff[i]) - height[i]
        return total