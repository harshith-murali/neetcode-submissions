class Solution {
public:
    string trim(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start < s.size() && isspace(s[start])) {
        start++;
    }

    while (end >= start && isspace(s[end])) {
        end--;
    }

    return s.substr(start, end - start + 1);
}
    int lengthOfLastWord(string s) {
       s = trim(s);
        int n = s.length();
        int cnt = 0;
        // remove initial trailing spaces
        for(int i=n-1; i>=0; i--){
            if(s[i] == ' ') break;
            else cnt++;
        }

        return cnt;
    }
};