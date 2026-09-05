class Solution:
    def largestRectangleArea(self, height: List[int]) -> int:
        n = len(height)
        st = []
        left = [0] * n
        for i in range(0,n):
            while st and height[st[-1]]>=height[i]:
                st.pop()
            left[i] = st[-1] if st else -1
            st.append(i)
        right = [0] * n
        st.clear()
        for i in range(n-1,-1,-1):
            while st and height[st[-1]]>=height[i]:
                st.pop()
            right[i] = st[-1] if st else n
            st.append(i)
        maxArea = 0
        for i in range(0,n):
            width = right[i] - left[i] - 1
            area = width * height[i]
            maxArea = max(area, maxArea)
        return maxArea