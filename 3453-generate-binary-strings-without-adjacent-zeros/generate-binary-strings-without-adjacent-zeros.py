class Solution:
    def validStrings(self, n: int) -> List[str]:
        def solve(i, curr, ans, n, canInclude0):
            if i == n:
                ans.append(curr)
                return
            if canInclude0 is True:
                curr+='0'
                solve(i+1,curr,ans,n,False)
                curr = curr[:-1]
                curr+='1'
                solve(i+1,curr,ans,n,True)
                curr = curr[:-1]
            else:
                curr+='1'
                solve(i+1,curr,ans,n,True)
                curr = curr[:-1]
        ans = []
        curr = ""
        solve(0,curr,ans,n,True)
        return ans