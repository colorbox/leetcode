/*
Amortized O(1)となるコードを誤解していたのを指摘されたので、書き直す。
push時にpush_stackにpop_stackから要素を移動させてくる必要はない。
pop_stackの中身が足りなくなってから(peek/pop時)push_stackの要素を移動させてくれば良く、その逆の移動は不要。
*/
class MyQueue {
public:
    stack<int> push_stack;
    stack<int> pop_stack;

    MyQueue() {}
    
    void push(int x) {
        push_stack.push(x);
    }
    
    int pop() {
        int pop_value = peek();
        pop_stack.pop();
        return pop_value;
    }
    
    int peek() {
        if (empty()) {
            return -1;
        }
        if (pop_stack.empty()){
            while (!push_stack.empty()) {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
        return pop_stack.top();
    }
    
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
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
