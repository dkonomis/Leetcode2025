class MinStack {
private:
    std::stack<int> stack;      // Main stack for values.
    std::stack<int> min_stack;  // Stack to track minimums.
    
public:
    MinStack() {
        /**
         * Problem: 0155 - Min Stack
         * 
         * Design a stack with O(1) push, pop, top, and getMin operations.
         * 
         * Approach:
         * Use two stacks - one for values, one for minimums.
         * Min stack stores the minimum value at each state of the main stack.
         * This allows O(1) retrieval of minimum at any time.
         * 
         * Time complexity: O(1) for all operations.
         * Space complexity: O(n) for storing n elements.
         */
    }
    
    void push(int val) {
        // Push value to main stack.
        stack.push(val);
        
        // Push new minimum to min stack.
        // If min_stack is empty, val is the minimum.
        // Otherwise, minimum is the smaller of val and current min.
        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            min_stack.push(std::min(val, min_stack.top()));
        }
    }
    
    void pop() {
        // Remove top element from both stacks.
        stack.pop();
        min_stack.pop();
    }
    
    int top() {
        // Get top element of stack.
        return stack.top();
    }
    
    int getMin() {
        // Get minimum element in O(1) time.
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
