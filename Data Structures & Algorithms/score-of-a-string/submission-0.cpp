class Solution {
public:
    int scoreOfString(string s) {
        int i = 0, j = 1;
        int n = s.length();
        int score = 0;
        while(j<n){
            score += abs(s[i++] - s[j++]);
        }
        return score;
    }
};