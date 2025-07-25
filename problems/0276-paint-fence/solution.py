class Solution:
    def numWays(self, n: int, k: int) -> int:
        """
        Problem: 0276 - Paint Fence
        
        Paint n posts with k colors such that no more than two adjacent
        posts have the same color. Use dynamic programming tracking total
        ways to paint i posts, using the recurrence:
        dp[i] = (k-1) * (dp[i-1] + dp[i-2])
        
        Time complexity: O(n).
        Space complexity: O(1).
        """
        # Base cases.
        if n == 1:
            return k
        
        # Track ways to paint posts.
        two_posts_back = k  # Ways to paint 1 post.
        one_post_back = k * k  # Ways to paint 2 posts.
        
        # Process remaining posts.
        for i in range(3, n + 1):
            # Current post can be painted (k-1) colors.
            # It can differ from previous post: dp[i-1] * (k-1).
            # Or be same as previous (but prev differs from its prev): dp[i-2] * (k-1).
            curr = (k - 1) * (one_post_back + two_posts_back)
            
            # Slide the window.
            two_posts_back = one_post_back
            one_post_back = curr
        
        res = one_post_back
        return res
