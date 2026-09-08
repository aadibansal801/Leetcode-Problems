class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        i = 0
        j = 0
        ans = 0
        mp = {}
        maxFreq = 0
        while j<n:
            mp[s[j]] = mp.get(s[j],0)+1
            maxFreq = max(maxFreq, mp[s[j]])
            while (j-i+1) - maxFreq > k:
                mp[s[i]]-=1
                i+=1
            ans = max(j-i+1, ans)
            j+=1
        return ans