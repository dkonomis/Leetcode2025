/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *  };
 */

class PeekingIterator : public Iterator {
private:
    bool has_peeked;
    int peeked_element;
    
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        /**
         * Problem: 0284 - Peeking Iterator
         * 
         * Design an iterator that supports peek() operation in addition to
         * the standard next() and hasNext() operations. The peek() should
         * return the next element without advancing the iterator.
         * 
         * Approach:
         * - Cache the next element when peek() is called
         * - Use a flag to track whether we have a cached element
         * - When next() is called, return cached element if available
         * 
         * Time complexity: O(1) for all operations.
         * Space complexity: O(1) for storing cached element.
         */
        has_peeked = false;
        peeked_element = 0;
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        // If we haven't peeked yet, cache the next element.
        if (!has_peeked) {
            peeked_element = Iterator::next();
            has_peeked = true;
        }
        return peeked_element;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        // If we have a cached element, return it.
        if (has_peeked) {
            int res = peeked_element;
            has_peeked = false;
            peeked_element = 0;
            return res;
        }
        // Otherwise, get the next element from iterator.
        return Iterator::next();
    }
    
    bool hasNext() const {
        // We have next if we have cached element or iterator has next.
        return has_peeked || Iterator::hasNext();
    }
};
