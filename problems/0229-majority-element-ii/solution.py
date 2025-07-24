class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        """
        Problem: 0229 - Majority Element II
        
        Find all elements appearing more than n/3 times.
        Use Boyer-Moore Voting Algorithm with two candidates.
        At most 2 elements can appear more than n/3 times.
        First pass: find potential candidates.
        Second pass: verify candidates actually appear > n/3 times.
        
        Time complexity: O(n) with two passes through the array.
        Space complexity: O(1) using only constant extra space.
        """
        # Phase 1: Find at most 2 potential candidates.
        candidate1, candidate2 = None, None
        count1, count2 = 0, 0
        
        for num in nums:
            # If num matches a candidate, increment its count.
            if candidate1 == num:
                count1 += 1
            elif candidate2 == num:
                count2 += 1
            # If a count is 0, replace that candidate.
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            elif count2 == 0:
                candidate2 = num
                count2 = 1
            # If num doesn't match either candidate, decrement both counts.
            else:
                count1 -= 1
                count2 -= 1
        
        # Phase 2: Verify candidates appear more than n/3 times.
        res = []
        threshold = len(nums) // 3
        
        # Count occurrences of each candidate.
        count1 = sum(1 for num in nums if num == candidate1)
        count2 = sum(1 for num in nums if num == candidate2)
        
        # Add to result if appears more than n/3 times.
        if count1 > threshold:
            res.append(candidate1)
        if candidate2 != candidate1 and count2 > threshold:
            res.append(candidate2)
        
        return res
