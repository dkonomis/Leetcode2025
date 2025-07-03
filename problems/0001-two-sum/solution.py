from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Problem: 0001 - Two Sum

        Given an array of integers and a target value, return the indices of 
        the two numbers such that they add up to the target.

        Approach:
        - Use a hash map (dictionary) to store previously seen numbers and their indices.
        - For each number in the array:
            - Calculate the complement (target - current number)
            - If the complement is already in the map, return the pair of indices.
            - Otherwise, store the current number with its index in the map.

        Time Complexity: O(n)
        Space Complexity: O(n)
        """

        map_ = {}  # Dictionary to store seen numbers and their indices.
        for idx in range(len(nums)):
            remain = target - nums[idx] # The number we are looking to find.
            if remain in map_:
		# Found the complement -- return indices.
                return [map_[remain], idx]
	    # Store the current number with its index.
            map_[nums[idx]] = idx

