from collections import deque, defaultdict

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        Problem: 0207 - Course Schedule
        
        Given number of courses and prerequisites, determine if it's possible to
        finish all courses. A cycle in prerequisites makes it impossible.
        
        Approach: Use topological sorting with Kahn's algorithm. Build graph and
        track in-degrees. Process nodes with 0 in-degree, reducing neighbors' in-degrees.
        
        Time complexity: O(V + E) where V is courses and E is prerequisites.
        Space complexity: O(V + E) for graph and in-degree array.
        """
        # Build adjacency list and in-degree array.
        graph = defaultdict(list)
        in_degree = [0] * numCourses
        
        for course, prereq in prerequisites:
            # prereq -> course (prereq must be taken before course).
            graph[prereq].append(course)
            in_degree[course] += 1
        
        # Find all courses with no prerequisites (in-degree = 0).
        queue = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                queue.append(i)
        
        completed_courses = 0
        
        # Process courses with no remaining prerequisites.
        while queue:
            # Take a course with no prerequisites.
            current_course = queue.popleft()
            completed_courses += 1
            
            # For each course that depends on current_course.
            for next_course in graph[current_course]:
                # Reduce its in-degree (one prerequisite completed).
                in_degree[next_course] -= 1
                # If all prerequisites are completed, add to queue.
                if in_degree[next_course] == 0:
                    queue.append(next_course)
        
        # If we completed all courses, no cycle exists.
        return completed_courses == numCourses
