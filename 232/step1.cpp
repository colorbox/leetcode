/*

push: 
  Time: O(N)
  Space: O(N)
O(N)
pop: 
  Time: O(1)
  Space: O(1)
peek: 
  Time: O(1)
  Space: O(1)
empty: 
  Time: O(1)
  Space: O(1)


### 思考の流れ

スタックとキューはデータの取り出し口の位置が異なるだけで同じことをしているという前提がある
このことからスタックの中に、数値を逆順にしたものを入れておけばキューの動作を実現できると気づく
要素群を持つスタックAから、スタックBに対して要素をすべて渡すと順序が逆になる。
これを利用してスタック感の要素の受け渡しでreveseを行う

push時は片方のスタックに一時的に全ての要素を対比させる。
空にしたスタックに対して新規要素を入れ、先ほど退避した要素をすべて戻すことで逆順を維持したまま新規要素をpushできる。
残りのメソッドは特に悩む要素がないのでスタックのメソッドを用いて実装する。
*/
class MyQueue {
public:
    stack<int> main;
    stack<int> tmp;

    MyQueue() {}
    
    void push(int x) {
        while (!main.empty()) {
            tmp.push(main.top());
            main.pop();
        }
        tmp.push(x);
        while (!tmp.empty()) {
            main.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        int top_value = main.top();
        main.pop();
        return top_value;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();        
    }
};
