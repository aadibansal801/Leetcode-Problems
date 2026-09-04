class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        n = len(num)
        st = []
        for i in num:
            while st and k>0 and st[-1] > i:
                st.pop()
                k-=1
            st.append(i)
        while k>0:
            st.pop()
            k-=1
        res = ""
        while st:
            res += st.pop()
        while len(res)!=0 and res[-1] == '0':
            res = res[:-1]
        res = res[::-1]
        return res if res else "0"
        