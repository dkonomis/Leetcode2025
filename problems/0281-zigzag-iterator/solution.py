from collections import deque

class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        """
        Using deque to store (index, vector) pairs
        """
        self.vectors = [v1, v2]
        self.queue = deque()
        
        # Add non-empty vectors to queue with their starting index
        for i, v in enumerate(self.vectors):
            if v:
                self.queue.append((0, i))  # (index_in_vector, vector_id)
    
    def next(self) -> int:
        # Get the next position from queue
        idx, vec_id = self.queue.popleft()
        
        # Get the value
        res = self.vectors[vec_id][idx]
        
        # If there are more elements in this vector, add it back
        if idx + 1 < len(self.vectors[vec_id]):
            self.queue.append((idx + 1, vec_id))
        
        return res
    
    def hasNext(self) -> bool:
        return len(self.queue) > 0
