class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        m = {}
        for i in range(len(nums)):
            m[nums[i]] = m.get(nums[i], 0) + 1
        return min(m, key=m.get)
