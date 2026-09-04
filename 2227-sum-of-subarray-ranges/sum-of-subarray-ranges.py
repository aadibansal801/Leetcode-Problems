class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        def sumSubarrayMaxs(nums):
            def findNGE(nums):
                st = []
                n = len(nums)
                ans = [0] * n
                for i in range(n-1,-1,-1):
                    while st and nums[st[-1]]<=nums[i]:
                        st.pop()
                    ans[i] = st[-1] if st else n
                    st.append(i)
                return ans
            
            def findPGE(nums):
                st = []
                n = len(nums)
                ans = [0] * n
                for i in range(0,n):
                    while st and nums[st[-1]]<nums[i]:
                        st.pop()
                    ans[i] = st[-1] if st else -1
                    st.append(i)
                return ans
            
            nge = findNGE(nums)
            pge = findPGE(nums)
            n = len(nums)
            total = 0
            for i in range(0,n):
                left = i - pge[i]
                right = nge[i] - i
                freq = left * right
                val = freq * nums[i]
                total+=val
            return total

        def sumSubarrayMins(nums):
            def findNSE(nums):
                st = []
                n = len(nums)
                ans = [0] * n
                for i in range(n-1, -1, -1):
                    while st and nums[st[-1]] >= nums[i]:
                        st.pop()
                    ans[i] = st[-1] if st else n
                    st.append(i)
                return ans
            
            def findPSE(nums):
                st = []
                n = len(nums)
                ans = [0]*n
                for i in range(0,n):
                    while st and nums[st[-1]] > nums[i]:
                        st.pop()
                    ans[i] = st[-1] if st else -1
                    st.append(i)
                return ans
            
            nse = findNSE(nums)
            pse = findPSE(nums)
            n = len(nums)
            total = 0
            for i in range(0,n):
                left = i - pse[i]
                right = nse[i] - i
                freq = left * right
                val = freq * nums[i]
                total += val
            return total

        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums)