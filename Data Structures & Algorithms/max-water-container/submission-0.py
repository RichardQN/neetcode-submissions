class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        max_val = 0

        while left != right:
            length = right - left
            if heights[left] > heights[right]:
                temp = length * heights[right]
                right -= 1
            else:
                temp = length * heights[left]
                left += 1
            if max_val > temp:
                continue
            else:
                max_val = temp
        return max_val
            