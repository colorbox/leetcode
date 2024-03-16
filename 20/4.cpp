class Solution {
public:
    std::map <char, char> parentheses = { 
        { '{', '}' }, 
        { '(', ')' }, 
        { '[', ']' },
    };

    bool isValid(string s) {
        stack<char> stack;

        for(char c : s){
            if(stack.empty() && isCloseParenth(c)){return false;}
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
        return parentheses[l] == r;
    }

    bool isCloseParenth(char c){
        for(auto p: parentheses){
            if(p.second == c){return true;}
        }
        return false;
    }

    bool isInvalidPair(char l, char r){
        return isCloseParenth(r) && parentheses[l] != r;
    }
};
