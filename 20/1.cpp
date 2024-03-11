class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(char c : s){
            // stack topとのチェック
            if(!stack.empty() && isPair(stack.top(), c)){
                stack.pop();
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }

    bool isPair(char l, char r){
        return (l == '(' && r == ')' || l == '{' && r == '}' || l == '[' && r == ']');
    }
};
