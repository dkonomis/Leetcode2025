# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
    def __init__(self, iterator):
        """
        Problem: 0284 - Peeking Iterator
        
        Design an iterator that supports peek() operation in addition to
        the standard next() and hasNext() operations. The peek() should
        return the next element without advancing the iterator.
        
        Approach:
        - Cache the next element when peek() is called
        - Use a flag to track whether we have a cached element
        - When next() is called, return cached element if available
        
        Time complexity: O(1) for all operations.
        Space complexity: O(1) for storing cached element.
        """
        self.iterator = iterator
        self.has_peeked = False
        self.peeked_element = None

    def peek(self):
        # If we haven't peeked yet, cache the next element.
        if not self.has_peeked:
            self.peeked_element = self.iterator.next()
            self.has_peeked = True
        return self.peeked_element

    def next(self):
        # If we have a cached element, return it.
        if self.has_peeked:
            res = self.peeked_element
            self.has_peeked = False
            self.peeked_element = None
            return res
        # Otherwise, get the next element from iterator.
        return self.iterator.next()

    def hasNext(self):
        # We have next if we have cached element or iterator has next.
        return self.has_peeked or self.iterator.hasNext()


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
