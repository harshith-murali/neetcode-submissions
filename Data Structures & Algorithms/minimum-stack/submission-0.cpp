class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }
    }
    
    void pop() {
        int popped = st.top();
        st.pop();

        if(popped == minSt.top()) minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
