class Solution {
public:
    bool isValid(string str) {
        stack<char> s;

        for(char ch : str){
            if(s.empty() || ch == '(' || ch == '{' || ch == '['){
                s.push(ch);
                continue;
            }

            if(ch == ')'){
                if(s.top() == '('){
                    s.pop();
                }else return false;
            }
            else if(ch == '}'){
                if(s.top() == '{'){
                    s.pop();
                }else return false;
            }

            else if(ch == ']'){
                if(s.top() == '['){
                    s.pop();
                }else return false;
            }

        }
        return s.empty();
    }
};
