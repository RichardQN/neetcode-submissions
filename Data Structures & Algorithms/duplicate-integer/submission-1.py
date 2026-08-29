class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        check = set()
        for i, n in enumerate(nums):
            if n in check:
                return True
            check.add(n)
        return False
