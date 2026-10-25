class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int(int, int)>> operate = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

        stack<int> st;

        for (string &token : tokens) {
            if (operate.count(token)) {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                st.push(operate[token](a, b));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};