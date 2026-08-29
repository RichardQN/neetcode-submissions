class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        cs = {}
        cm = {}
        for i in range(len(s)):
            cs[s[i]] = cs.get(s[i], 0) + 1
            cm[t[i]] = cm.get(t[i], 0) + 1
        
        if cs == cm:
            return True
        else:
            return False