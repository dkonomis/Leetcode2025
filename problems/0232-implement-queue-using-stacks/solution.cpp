class MyQueue {
public:
    /*
     * Problem: 0232 - Implement Queue using Stacks
     * 
     * Implement FIFO queue using two stacks.
     * Use input stack for push operations and output stack for pop/peek.
     * Transfer elements from input to output stack when needed.
     * This achieves amortized O(1) time for all operations.
     * 
     * Time complexity: O(1) amortized for all operations.
     * Space complexity: O(n) where n is the number of elements.
     */
    
    MyQueue() {
        // Constructor - stacks are already initialized.
    }
    
    void push(int x) {
        // Always push new elements to input stack.
        input_stack.push(x);
    }
    
    int pop() {
        // Ensure output stack has elements.
        moveInputToOutput();
        // Pop from output stack (front of queue).
        int front = output_stack.top();
        output_stack.pop();
        return front;
    }
    
    int peek() {
        // Ensure output stack has elements.
        moveInputToOutput();
        // Return top of output stack without removing.
        return output_stack.top();
    }
    
    bool empty() {
        // Queue is empty if both stacks are empty.
        return input_stack.empty() && output_stack.empty();
    }
    
private:
    stack<int> input_stack;   // Input stack for new elements.
    stack<int> output_stack;  // Output stack for dequeue operations.
    
    void moveInputToOutput() {
        // Transfer elements only when output stack is empty.
        if (output_stack.empty()) {
            // Move all elements from input to output.
            // This reverses the order, making LIFO become FIFO.
            while (!input_stack.empty()) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
