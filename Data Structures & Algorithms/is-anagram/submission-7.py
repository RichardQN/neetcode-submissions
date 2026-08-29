class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        i = 1
        c1, c2 = [0]*26, [0]*26
        for i in range(len(s)):
            c1[ord(s[i]) - ord('a')] += 1
            c2[ord(t[i]) - ord('a')] += 1
        
        if (c1 == c2):
            return True
        
        return False