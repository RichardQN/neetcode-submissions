class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.items = nums
        self.k = k
        heapq.heapify(self.items)
        while len(self.items) > k:
            heapq.heappop(self.items)
            

    def add(self, val: int) -> int:
        heapq.heappush(self.items, val)
        if len(self.items) > self.k:
            heapq.heappop(self.items)
        return self.items[0]