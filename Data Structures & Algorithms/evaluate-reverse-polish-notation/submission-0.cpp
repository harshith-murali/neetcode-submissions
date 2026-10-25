class Solution {
public:
    int operate(int a , int b, string token){
        if(token == "+"){
            return a + b;
        }
        if(token == "-"){
            return a - b;
        }
        if(token == "*"){
            return a * b;
        }
        if(token == "/"){
            return a / b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string &token : tokens){
            if(token == "+" || token == "-" 
            || token == "*" || token == "/"){
                // take top 2 elements and perform operation and push result in stack
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result = operate(a , b , token);
                st.push(result);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
