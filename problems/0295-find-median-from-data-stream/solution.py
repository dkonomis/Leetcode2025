import heapq

class MedianFinder:
    def __init__(self):
        """
        Problem: 0295 - Find Median from Data Stream
        
        Maintain the median of a stream of numbers efficiently using two heaps:
        - A max heap for the smaller half of numbers
        - A min heap for the larger half of numbers
        
        The invariant is that max_heap can have at most one more element than min_heap.
        The median is either the top of max_heap (odd total) or the average of both tops (even total).
        
        Time complexity: O(log n) for addNum, O(1) for findMedian.
        Space complexity: O(n), where n is the number of elements added.
        """
        # Max heap for smaller half (Python heapq is min heap, so negate values).
        self.max_heap = []
        # Min heap for larger half.
        self.min_heap = []

    def addNum(self, num: int) -> None:
        # Always add to max_heap first.
        heapq.heappush(self.max_heap, -num)
        
        # Move the largest from max_heap to min_heap.
        heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        
        # Balance the heaps if min_heap has more elements.
        if len(self.min_heap) > len(self.max_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def findMedian(self) -> float:
        # If odd number of elements, median is top of max_heap.
        if len(self.max_heap) > len(self.min_heap):
            return -self.max_heap[0]
        # If even number of elements, median is average of both tops.
        return (-self.max_heap[0] + self.min_heap[0]) / 2.0
