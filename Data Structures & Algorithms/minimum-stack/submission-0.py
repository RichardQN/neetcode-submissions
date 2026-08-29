class MinStack:

    def __init__(self):
        self.items = []

    def push(self, val: int) -> None:
        if (val) is not None:
            self.items.append(val)
        else:
            return None

    def pop(self) -> None:
        if self.items:
            return self.items.pop()
        else:
            return None

    
    def top(self) -> int:
        return self.items[-1]
        

    def getMin(self) -> int:
        return min(self.items)
        
