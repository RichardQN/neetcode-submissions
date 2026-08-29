class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        num_col = len(matrix[0])
        num_row = len(matrix)
        left = 0
        right = num_col * num_row - 1
        mid = 0
        while (left <= right):
            mid = (left + right)//2
            if ((matrix[mid // num_col][mid % num_col]) > target):
                right = mid - 1
            elif ((matrix[mid // num_col][mid % num_col]) < target):
                left = mid + 1
            elif ((matrix[mid // num_col][mid % num_col]) == target):
                return True
            
        return False


        


