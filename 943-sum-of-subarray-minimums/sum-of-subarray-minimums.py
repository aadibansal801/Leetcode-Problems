class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        def findNSE(arr):
            n = len(arr)
            ans = [0] * n
            st = []
            for i in range(n-1, -1, -1):
                while st and arr[st[-1]] >= arr[i]:
                    st.pop()
                ans[i] = st[-1] if st else n
                st.append(i)
            return ans
        def findPSE(arr):
            n = len(arr)
            ans = [0] * n
            st = []
            for i in range (0,n):
                while st and arr[st[-1]] > arr[i]:
                    st.pop()
                ans[i] = st[-1] if st else -1
                st.append(i)
            return ans
        nse = findNSE(arr)
        pse = findPSE(arr)
        n = len(arr)
        mod = (int)(1e9+7)
        total = 0
        for i in range(0,n):
            left = i - pse[i]
            right = nse[i] - i
            freq = left*right
            val = (freq*arr[i])%mod
            total = (total + val)%mod
        return total