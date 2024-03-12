class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        if(s[0] == ')' || s[0] == '}' || s[0] == ']'){
            return false;
        }

        for(char c : s){
            if(!stack.empty() && isInvalidPair(stack.top(), c)){return false;}
            
            if(c != '(' && c != '{' && c != '[' && !stack.empty() && isPair(stack.top(), c)){
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

    bool isInvalidPair(char l, char r){
        return (l == '(' && (r == '}' || r == ']')) || (l == '{' && (r == ')' || r == ']')) || (l == '[' && (r == '}' || r == ')'));
    }
};
