class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
         * Problem: 0210 - Course Schedule II
         * Given number of courses and prerequisites, return the ordering of courses
         * to take to finish all courses. Return empty array if impossible.
         * 
         * Approach: Use topological sorting with Kahn's algorithm. Build graph and
         * track in-degrees. Process nodes with 0 in-degree, recording the order.
         * 
         * Time complexity: O(V + E) where V is courses and E is prerequisites.
         * Space complexity: O(V + E) for graph and in-degree array.
         */
        
        // Build adjacency list and in-degree array.
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            // prerequisite -> course (prerequisite must be taken before course).
            graph[prerequisite].push_back(course);
            in_degree[course]++;
        }
        
        // Find all courses with no prerequisites (in-degree = 0).
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> course_order;
        
        // Process courses with no remaining prerequisites.
        while (!q.empty()) {
            // Take a course with no prerequisites.
            int current_course = q.front();
            q.pop();
            // Add to our course ordering.
            course_order.push_back(current_course);
            
            // For each course that depends on current_course.
            for (int next_course : graph[current_course]) {
                // Reduce its in-degree (one prerequisite completed).
                in_degree[next_course]--;
                // If all prerequisites are completed, add to queue.
                if (in_degree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }
        
        // If we processed all courses, return order; otherwise return empty (cycle detected).
        return course_order.size() == numCourses ? course_order : vector<int>();
    }
};
