class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        n = len(fruits)
        i = 0
        j = 0
        mp = {}
        ans = 0
        while(j<n):
            mp[fruits[j]] = mp.get(fruits[j],0)+1
            while len(mp)>2:
                mp[fruits[i]]-=1
                if mp[fruits[i]] == 0:
                    del mp[fruits[i]]
                i+=1
            ans = max(ans, j-i+1)
            j+=1
        return ans