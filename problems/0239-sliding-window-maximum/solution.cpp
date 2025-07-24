class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
         * Problem: 0239 - Sliding Window Maximum
         * 
         * Find maximum in each sliding window of size k.
         * Use a deque to maintain indices of elements in decreasing order.
         * The front of deque always contains index of the maximum element.
         * Clean deque by removing indices outside window and smaller elements.
         * 
         * Time complexity: O(n) where n is the length of nums.
         * Space complexity: O(k) for the deque.
         */
        
        // Base cases.
        int n = nums.size();
        // Empty array.
        if (n == 0 || k == 0) {
            return {};
        }
        // Window size 1 means every element is its own maximum.
        if (k == 1) {
            return nums;
        }
        
        deque<int> deq;
        vector<int> output;
        
        // Helper lambda to clean deque.
        auto clean_deque = [&](int i) {
            // Remove indexes of elements not from sliding window.
            // If leftmost index is now outside the window, remove it.
            if (!deq.empty() && deq.front() == i - k) {
                deq.pop_front();
            }
            
            // Remove from deq indexes of all elements.
            // which are smaller than current element nums[i].
            // These elements can never be maximum in any future window.
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
        };
        
        // Process first window separately.
        for (int i = 0; i < k; i++) {
            // Clean deque and add current index.
            clean_deque(i);
            deq.push_back(i);
        }
        
        // First window's maximum is at front of deque.
        output.push_back(nums[deq.front()]);
        
        // Build output for remaining windows.
        for (int i = k; i < n; i++) {
            // Clean deque for new element at index i.
            clean_deque(i);
            // Add current index to deque.
            deq.push_back(i);
            // Front of deque has the maximum for current window.
            output.push_back(nums[deq.front()]);
        }
        
        return output;
    }
};
