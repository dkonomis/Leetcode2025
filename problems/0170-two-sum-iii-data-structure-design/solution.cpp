class TwoSum {
public:
    /*
    Problem: 0170 - Two Sum III - Data Structure Design
    
    Design data structure to support add numbers and find if any pair sums to target.
    Optimize for fast add operations with acceptable find performance.
    
    Approach:
    - Use HashMap to store number frequencies for O(1) add operations
    - For find, iterate through all stored numbers and check for valid complement
    - Handle two cases: different numbers (need complement to exist) and 
      same number (need frequency > 1 for cases like 3+3=6)
    
    Time complexity: add O(1), find O(n).
    Space complexity: O(n).
    */
    
    TwoSum() {
        // Initialize with empty frequency map.
    }
    
    void add(int number) {
        // Increment frequency count for this number.
        num_freq[number]++;
    }
    
    bool find(int value) {
        // Check each stored number for a valid complement.
        for (auto& pair : num_freq) {
            int num = pair.first;
            int freq = pair.second;
            
            // Use long long to avoid integer overflow when calculating complement.
            long long complement = (long long)value - num;
            
            if (complement != num) {
                // Different numbers: just need complement to exist.
                // Check if complement is in valid int range before lookup.
                if (complement >= INT_MIN && complement <= INT_MAX && 
                    num_freq.count((int)complement)) {
                    return true;
                }
            } else if (freq > 1) {
                // Same number case: need at least 2 occurrences (num + num = value).
                return true;
            }
        }
        
        return false;
    }

private:
    unordered_map<int, int> num_freq;  // Maps number to its frequency.
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
