class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /**
         * Problem: 0215 - Kth Largest Element in an Array
         * 
         * Use QuickSelect with three-way partitioning to find kth largest element.
         * We convert kth largest to (n-k+1)th smallest and solve accordingly.
         * This handles duplicates efficiently and avoids worst-case scenarios.
         * 
         * Time complexity: O(n) average case, O(n^2) worst case.
         * Space complexity: O(n) for the partition arrays.
         */
        
        // Convert kth largest to (n-k+1)th smallest.
        int n = nums.size();
        int k_smallest = n - k + 1;
        
        return quickSelect(nums, k_smallest);
    }
    
private:
    int quickSelect(vector<int> nums, int k) {
        // Choose random pivot.
        int pivot_index = rand() % nums.size();
        int pivot = nums[pivot_index];
        
        vector<int> left, mid, right;
        
        // Three-way partition: elements < pivot, = pivot, > pivot.
        for (int num : nums) {
            if (num < pivot) {
                left.push_back(num);
            } else if (num > pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        // If k-th smallest is in left (smaller elements).
        if (k <= left.size()) {
            return quickSelect(left, k);
        }
        
        // If k-th smallest is in right (larger elements).
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }
        
        // k-th smallest is the pivot.
        return pivot;
    }
};
