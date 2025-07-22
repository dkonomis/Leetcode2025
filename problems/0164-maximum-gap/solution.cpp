class Solution {
public:
    int maximumGap(vector<int>& nums) {
        /*
        Problem: 0164 - Maximum Gap
        
        Find maximum difference between successive elements in sorted form.
        Must solve in O(n) time and O(n) space.
        
        Approach:
        - Use bucket sort concept with pigeonhole principle
        - Create n-1 buckets with gap size = (max-min)/(n-1)
        - Maximum gap must be between buckets, not within buckets
        - Only store min/max for each bucket to save space
        - Find max difference between max of one bucket and min of next non-empty bucket
        
        Time complexity: O(n).
        Space complexity: O(n).
        */
        
        if (nums.size() < 2) {
            return 0;
        }
        
        int n = nums.size();
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        // If all elements are the same, gap is 0.
        if (min_val == max_val) {
            return 0;
        }
        
        // Calculate bucket size using ceiling division.
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;
        
        // Initialize buckets to store min and max values.
        vector<pair<int, int>> buckets(bucket_count, {INT_MAX, INT_MIN});
        
        // Place each number into appropriate bucket.
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            buckets[idx].first = min(buckets[idx].first, num);   // Update min.
            buckets[idx].second = max(buckets[idx].second, num); // Update max.
        }
        
        // Find maximum gap between buckets.
        int res = 0;
        int prev_max = min_val;
        
        for (auto& bucket : buckets) {
            // Skip empty buckets.
            if (bucket.first == INT_MAX) {
                continue;
            }
            
            // Gap between previous bucket's max and current bucket's min.
            res = max(res, bucket.first - prev_max);
            prev_max = bucket.second;
        }
        
        return res;
    }
};
