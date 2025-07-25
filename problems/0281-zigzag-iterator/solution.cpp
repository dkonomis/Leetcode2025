class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> queue;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        /**
         * Problem: 0281 - Zigzag Iterator
         * 
         * Given two 1d vectors, implement an iterator to return their
         * elements alternately. Uses a queue of iterator pairs (current, end)
         * to manage the alternating pattern.
         * 
         * Approach:
         * - Store pairs of iterators (current position, end position) in a queue
         * - For next(), dequeue a pair, get current element, advance iterator,
         *   and re-enqueue if not at end
         * - This approach easily extends to k vectors
         * 
         * Time complexity: O(1) for both next() and hasNext().
         * Space complexity: O(k) where k is the number of vectors.
         */
        
        // Add iterator pairs for non-empty vectors.
        if (!v1.empty()) {
            queue.push({v1.begin(), v1.end()});
        }
        if (!v2.empty()) {
            queue.push({v2.begin(), v2.end()});
        }
    }
    
    int next() {
        // Get the next iterator pair from the front of the queue.
        auto current = queue.front().first;
        auto end = queue.front().second;
        queue.pop();
        
        // Get the value at the current position.
        int res = *current;
        
        // Advance the iterator.
        current++;
        
        // If there are more elements, add the pair back to the queue.
        if (current != end) {
            queue.push({current, end});
        }
        
        return res;
    }
    
    bool hasNext() {
        // We have more elements if the queue is not empty.
        return !queue.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
