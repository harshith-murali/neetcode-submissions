class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber){
            columnNumber--;
            int offset = columnNumber % 26;
            res += ('A' + offset);
            columnNumber /= 26;
        }
        reverse(begin(res), end(res));
        return res;
    }
};