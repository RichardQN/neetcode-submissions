class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        m = set(nums)
        res = 0
        for n in m:
            if (n-1) not in m:
                seq = 1
                while (n + seq) in m:
                    seq += 1
                res = max(res, seq)
        
        return res

            
            