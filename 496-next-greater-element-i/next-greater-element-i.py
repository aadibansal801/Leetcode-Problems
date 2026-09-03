class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums2)
        st = []
        mp = {}
        for i in range(n-1,-1,-1):
            while st and nums2[i]>=st[-1]:
                st.pop()
            if not st:
                mp[nums2[i]] = -1
            else:
                mp[nums2[i]] = st[-1]
            st.append(nums2[i])
        ans = []
        for it in nums1:
            ans.append(mp[it])
        return ans