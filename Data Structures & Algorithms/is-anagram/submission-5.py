class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cs = [0] * 26
        ct = [0] * 26
        for n in s:
            cs[ord(n) - ord('a')] += 1
        for m in t:
            ct[ord(m) - ord('a')] += 1
        
        if cs == ct:
            return True
        else:
            return False
        
        