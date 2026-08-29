class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mc = {}
        res = []
        for i, n in enumerate(nums):
            mc[n] = mc.get(n, 0) + 1
        
        while k != 0:
            max_key = max(mc, key=mc.get)
            res.append(max_key)
            mc.pop(max_key)
            k -= 1
        
        return res