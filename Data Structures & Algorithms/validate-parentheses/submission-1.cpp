class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(char ch : str){
            if(ch == '('){
                s.push(')');
            }else if(ch == '{'){
                s.push('}');
            }else if(ch == '['){
                s.push(']');
            }
            else if(s.empty() || s.top() != ch){
                return false;
            }else s.pop();
        }
        return s.empty();
    }
};
