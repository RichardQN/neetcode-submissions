class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m = set()
        l = 0
        res = 0
        for r in range(len(s)):
            while s[r] in m:
                m.discard(s[l])
                l += 1
            m.add(s[r])
            res = max(res, r - l + 1)
        return res


