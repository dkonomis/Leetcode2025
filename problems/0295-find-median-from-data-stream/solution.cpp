class MedianFinder {
public:
    MedianFinder() {
        /**
         * Problem: 0295 - Find Median from Data Stream
         * 
         * Maintain the median of a stream of numbers efficiently using two heaps:
         * - A max heap for the smaller half of numbers
         * - A min heap for the larger half of numbers
         * 
         * The invariant is that max_heap can have at most one more element than min_heap.
         * The median is either the top of max_heap (odd total) or the average of both tops (even total).
         * 
         * Time complexity: O(log n) for addNum, O(1) for findMedian.
         * Space complexity: O(n), where n is the number of elements added.
         */
    }
    
    void addNum(int num) {
        // Always add to max_heap first.
        max_heap.push(num);
        
        // Move the largest from max_heap to min_heap.
        min_heap.push(max_heap.top());
        max_heap.pop();
        
        // Balance the heaps if min_heap has more elements.
        if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        // If odd number of elements, median is top of max_heap.
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        // If even number of elements, median is average of both tops.
        return (max_heap.top() + min_heap.top()) / 2.0;
    }

private:
    // Max heap for smaller half (default priority_queue is max heap).
    priority_queue<int> max_heap;
    // Min heap for larger half (using greater<int> for min heap).
    priority_queue<int, vector<int>, greater<int>> min_heap;
};
