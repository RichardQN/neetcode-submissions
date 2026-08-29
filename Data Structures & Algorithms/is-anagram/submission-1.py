class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        word1 = {}
        word2 = {}

        for i, c in enumerate(s):
            word1[c] = word1.get(c, 0) + 1

        for i, c in enumerate(t):
            word2[c] = word2.get(c, 0) + 1

        if word1 == word2:
            return True
        else :
            return False