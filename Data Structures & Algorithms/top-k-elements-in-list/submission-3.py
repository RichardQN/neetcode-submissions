class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequencyMap = defaultdict(int)
        for n in nums:
            frequencyMap[n] += 1
        res = []
        while k > 0:
            s = max(frequencyMap, key=frequencyMap.get)
            res.append(s)
            frequencyMap.pop(s, None)
            k -= 1
        return res