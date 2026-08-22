class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        def solve(i,k,n,curr,ans,total):
            if(len(curr) == k):
                if(total == n):
                    ans.append(curr.copy())
                return
            if i > 9:
                return
            curr.append(i)
            solve(i+1,k,n,curr,ans,total+i)
            curr.pop()
            solve(i+1,k,n,curr,ans,total)
        curr = []
        ans = []
        solve(1,k,n,curr,ans,0)
        return ans