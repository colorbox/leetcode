/*
push: 
  Time: O(N) or O(1)
  Space: O(N) or O(1)
O(N)
pop: 
  Time: O(N) or O(1)
  Space: O(N) or O(1)
peek: 
  Time: O(N) or O(1)
  Space: O(N) or O(1)
empty: 
  Time: O(1)
  Space: O(1)
*/
class MyQueue {
public:

    stack<int> push_stack;
    stack<int> pop_stack;

    MyQueue() {}
    
    void push(int x) {
        while (!pop_stack.empty()) {
            push_stack.push(pop_stack.top());
            pop_stack.pop();
        }
        push_stack.push(x);
    }
    
    int pop() {
        int pop_value = peek();
        pop_stack.pop();
        return pop_value;
    }
    
    int peek() {
        while (!push_stack.empty()) {
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
        return pop_stack.top();
    }
    
    bool empty() {
        return pop_stack.empty() && push_stack.empty();
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
