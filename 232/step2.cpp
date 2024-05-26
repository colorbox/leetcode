/*
ロジック的な箇所はあまりいじる部分がないと感じたため変数名だけいじった
*/
class MyQueue {
public:
    stack<int> primary;
    stack<int> temporary;

    MyQueue() {}
    
    void push(int x) {
        while (!primary.empty()) {
            temporary.push(primary.top());
            primary.pop();
        }
        temporary.push(x);
        while (!temporary.empty()) {
            primary.push(temporary.top());
            temporary.pop();
        }
    }
    
    int pop() {
        int top_value = primary.top();
        primary.pop();
        return top_value;
    }
    
    int peek() {
        return primary.top();
    }
    
    bool empty() {
        return primary.empty();        
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
