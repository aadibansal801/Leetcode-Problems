class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        freq = [0]*26
        for i,j in zip(s,t):
            freq[ord(i) - ord('a')]+=1
            freq[ord(j) - ord('a')]-=1
        return all(x==0 for x in freq)