class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string curr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                numStack.push(num);
                strStack.push(curr);

                num = 0;
                curr = "";
            } 
            else if (ch == ']') {
                int k = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                string repeated = "";
                for (int i = 0; i < k; i++) {
                    repeated += curr;
                }

                curr = prev + repeated;
            } 
            else {
                curr += ch;
            }
        }

        return curr;
    }
};